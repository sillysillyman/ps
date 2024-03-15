#include <iostream>

using namespace std;
using ll = long long;

struct Point {
  ll x, y;
};

struct Line {
  Point p, q;
};

const int MAX_N = 2'000;
Line lines[MAX_N];
int intersections[MAX_N][MAX_N];

int ccw(Point p, Point q, Point r) {
  if (ll cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product)
    return cross_product / abs(cross_product);
  return 0;
}

bool is_point_on_line(Point p, Line l) {
  if (ccw(p, l.p, l.q)) return false;
  if (l.p.x > l.q.x || (l.p.x == l.q.x && l.p.y > l.q.y)) swap(l.p, l.q);
  return (l.p.x == l.q.x ? l.p.y <= p.y && p.y <= l.q.y
                         : l.p.x <= p.x && p.x <= l.q.x);
}

bool do_lines_overlap(Line l1, Line l2) {
  if (l1.p.x == l1.q.x || l2.p.x == l2.q.x) {
    if (l1.p.x == l1.q.x && l2.p.x == l2.q.x) {
      if (l1.p.y > l1.q.y) swap(l1.p, l1.q);
      if (l2.p.y > l2.q.y) swap(l2.p, l2.q);
      return l1.p.x == l2.p.x && l1.p.y < l2.q.y && l2.p.y < l1.q.y;
    }
    return false;
  }
  if (!ccw(l1.p, l1.q, l2.p) && !ccw(l1.p, l1.q, l2.q)) {
    if (l1.p.x > l1.q.x) swap(l1.p, l1.q);
    if (l2.p.x > l2.q.x) swap(l2.p, l2.q);
    return l1.p.x < l2.q.x && l2.p.x < l1.q.x;
  }
  return false;
}

int main() {
  int N;

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> lines[i].p.x >> lines[i].p.y >> lines[i].q.x >> lines[i].q.y;
  for (int i = 0; i < N; i++) intersections[i][i] = 3;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if ((is_point_on_line(lines[i].p, lines[j]) ||
           is_point_on_line(lines[i].q, lines[j]) ||
           is_point_on_line(lines[j].p, lines[i]) ||
           is_point_on_line(lines[j].q, lines[i])) &&
          !do_lines_overlap(lines[i], lines[j])) {
        intersections[i][j] = 1;
        intersections[j][i] = 1;
      } else if (ccw(lines[i].p, lines[i].q, lines[j].p) *
                         ccw(lines[i].p, lines[i].q, lines[j].q) <
                     0 &&
                 ccw(lines[j].p, lines[j].q, lines[i].p) *
                         ccw(lines[j].p, lines[j].q, lines[i].q) <
                     0) {
        intersections[i][j] = 2;
        intersections[j][i] = 2;
      } else if (do_lines_overlap(lines[i], lines[j])) {
        intersections[i][j] = 3;
        intersections[j][i] = 3;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cout << intersections[i][j];
    cout << '\n';
  }
}