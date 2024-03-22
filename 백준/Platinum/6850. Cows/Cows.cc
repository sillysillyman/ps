#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

Point points[10'000];
vector<Point> convex_hull;

int ccw(Point p, Point q, Point r) {
  if (int cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product)
    return cross_product / abs(cross_product);
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;
  sort(points, points + n, [](const Point& p, const Point& q) {
    return p.y == q.y ? p.x < q.x : p.y < q.y;
  });
  sort(points + 1, points + n, [](const Point& p, const Point& q) {
    int direction = ccw(points[0], p, q);

    if (!direction)
      return (points[0].x - p.x) * (points[0].x - p.x) +
                 (points[0].y - p.y) * (points[0].y - p.y) <
             (points[0].x - q.x) * (points[0].x - q.x) +
                 (points[0].y - q.y) * (points[0].y - q.y);
    return direction > 0;
  });

  int curr = 2;

  convex_hull.push_back(points[0]);
  convex_hull.push_back(points[1]);
  while (curr < n) {
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

  int size = convex_hull.size();
  double area = 0;

  for (int i = 1; i < size - 1; i++)
    area += 0.5 * abs(convex_hull[0].x * convex_hull[i].y +
                      convex_hull[i].x * convex_hull[i + 1].y +
                      convex_hull[i + 1].x * convex_hull[0].y -
                      convex_hull[i].x * convex_hull[0].y -
                      convex_hull[i + 1].x * convex_hull[i].y -
                      convex_hull[0].x * convex_hull[i + 1].y);
  cout << (int)(area / 50);
}