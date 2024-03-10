#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
using ll = long long;

struct Point {
  ll x, y;
};

struct Line {
  Point p, q;
};

int parents[3'000];
Line lines[3'000];
map<int, int> groups;

ll ccw(Point u, Point v, Point w) {
  return (v.x - u.x) * (w.y - u.y) - (v.y - u.y) * (w.x - u.x);
}

bool does_lines_intersect(Line l, Line m) {
  ll ccw1 = ccw(l.p, l.q, m.p) * ccw(l.p, l.q, m.q);
  ll ccw2 = ccw(m.p, m.q, l.p) * ccw(m.p, m.q, l.q);

  if (ccw1 == 0 && ccw2 == 0) {
    if (l.p.x > l.q.x || l.p.x == l.q.x && l.p.y > l.q.y) swap(l.p, l.q);
    if (m.p.x > m.q.x || m.p.x == m.q.x && m.p.y > m.q.y) swap(m.p, m.q);
    return !(l.q.x < m.p.x || (l.q.x == m.p.x && l.q.y < m.p.y) ||
             m.q.x < l.p.x || (m.q.x == l.p.x && m.q.y < l.p.y));
  }
  return ccw1 <= 0 && ccw2 <= 0;
}

int find(int x) {
  if (x == parents[x]) return x;
  return parents[x] = find(parents[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (x < y)
    parents[y] = x;
  else
    parents[x] = y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> lines[i].p.x >> lines[i].p.y >> lines[i].q.x >> lines[i].q.y;
    parents[i] = i;
  }
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (does_lines_intersect(lines[i], lines[j])) merge(i, j);
    }
  }
  for (int i = 0; i < N; i++) groups[find(i)]++;
  cout << groups.size() << '\n'
       << max_element(groups.begin(), groups.end(), [](auto& a, auto& b) {
            return a.second < b.second;
          })->second;
}