#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

Point points[1000];
vector<Point> convex_hull;

double magnitude(Point p) { return sqrt(p.x * p.x + p.y * p.y); }

int ccw(Point p, Point q, Point r) {
  if (int cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product)
    return cross_product / abs(cross_product);
  return 0;
}

int main() {
  int N, L;

  cin >> N >> L;
  for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
  sort(points, points + N, [](const Point& p, const Point& q) {
    return p.y == q.y ? p.x < q.x : p.y < q.y;
  });
  sort(points + 1, points + N, [&](const Point& p, const Point& q) {
    int direction = ccw(points[0], p, q);

    if (!direction)
      return (p.x - points[0].x) * (p.x - points[0].x) +
                 (p.y - points[0].y) * (p.y - points[0].y) <
             (q.x - points[0].x) * (q.x - points[0].x) +
                 (q.y - points[0].y) * (q.y - points[0].y);
    return direction > 0;
  });

  int curr = 2;

  convex_hull.push_back(points[0]);
  convex_hull.push_back(points[1]);
  while (curr < N) {
    while (convex_hull.size() >= 2) {
      Point prev_prev, prev;

      prev = convex_hull.back();
      convex_hull.pop_back();
      prev_prev = convex_hull.back();
      if (ccw(prev_prev, prev, points[curr]) > 0) {
        convex_hull.push_back(prev);
        break;
      }
    }
    convex_hull.push_back(points[curr++]);
  }
  convex_hull.push_back(convex_hull.front());

  int size = convex_hull.size();
  double perimeter = 0;

  perimeter += 2 * L * M_PI;
  for (int i = 0; i < size - 1; i++) {
    perimeter += magnitude({convex_hull[i + 1].x - convex_hull[i].x,
                            convex_hull[i + 1].y - convex_hull[i].y});
  }
  cout << round(perimeter);
}