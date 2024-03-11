#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Point {
  ll x, y;
};

Point points[5000];

int ccw(Point p, Point q, Point r) {
  if (ll cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product > 0)
    return 1;
  else if (cross_product < 0)
    return -1;
  else
    return 0;
}

double get_distance(Point p, Point q) {
  return sqrt((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y));
}

int main() {
  int N;
  vector<Point> s;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
  sort(points, points + N, [](const Point& p, const Point& q) {
    if (p.y == q.y) return p.x < q.x;
    return p.y < q.y;
  });
  sort(points + 1, points + N, [&](const Point& p, const Point& q) {
    int direction = ccw(points[0], p, q);

    if (direction == 0)
      return get_distance(points[0], p) > get_distance(points[0], q);
    return direction > 0;
  });

  int curr = 2;

  s.push_back(points[0]);
  s.push_back(points[1]);
  while (curr < N) {
    while (s.size() >= 2) {
      Point prev_prev, prev;

      prev = s.back();
      s.pop_back();
      prev_prev = s.back();
      if (ccw(prev_prev, prev, points[curr]) > 0) {
        s.push_back(prev);
        break;
      }
    }
    s.push_back(points[curr++]);
  }

  int size = s.size();
  double dist = 0;

  for (int i = 0; i < size - 1; i++) dist += get_distance(s[i], s[i + 1]);
  dist += get_distance(s[size - 1], s[0]);
  cout << fixed;
  cout.precision(2);
  cout << dist;
}