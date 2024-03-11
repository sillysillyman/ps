#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

struct Point {
  ll x, y;
};

Point points[100'000];
stack<Point> s;

int ccw(Point p, Point q, Point r) {
  ll cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);

  if (cross_product < 0)
    return -1;
  else if (cross_product > 0)
    return 1;
  else
    return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
  sort(points, points + N, [](const Point& p, const Point& q) {
    return p.y == q.y ? p.x < q.x : p.y < q.y;
  });
  sort(points + 1, points + N, [&](const Point& p, const Point& q) {
    int direction = ccw(points[0], p, q);

    if (direction == 0)
      return (p.x - points[0].x) * (p.x - points[0].x) +
                 (p.y - points[0].y) * (p.y - points[0].y) <
             (q.x - points[0].x) * (q.x - points[0].x) +
                 (q.y - points[0].y) * (q.y - points[0].y);
    return direction > 0;
  });

  int curr = 2;

  s.push(points[0]);
  s.push(points[1]);
  while (curr < N) {
    while (s.size() >= 2) {
      Point prev_prev, prev;

      prev = s.top();
      s.pop();
      prev_prev = s.top();
      if (ccw(prev_prev, prev, points[curr]) > 0) {
        s.push(prev);
        break;
      }
    }
    s.push(points[curr++]);
  }
  cout << s.size();
}