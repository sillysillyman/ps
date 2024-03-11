#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
  int x, y;
};

Point points[50];

int ccw(Point p, Point q, Point r) {
  if (int cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product > 0)
    return 1;
  else if (cross_product < 0)
    return -1;
  else
    return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int P;

  cin >> P;
  while (P--) {
    int N;
    vector<Point> s;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;
    sort(points, points + N, [](const Point& p, const Point& q) {
      if (p.y == q.y) return p.x < q.x;
      return p.y > q.y;
    });
    sort(points + 1, points + N, [&](const Point& p, const Point& q) {
      int direction = ccw(points[0], p, q);

      if (direction == 0)
        return (p.x - points[0].x) * (p.x - points[0].x) +
                   (p.y - points[0].y) * (p.y - points[0].y) <
               (q.x - points[0].x) * (q.x - points[0].x) +
                   (q.y - points[0].y) * (q.y - points[0].y);
      return direction < 0;
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
        if (ccw(prev_prev, prev, points[curr]) < 0) {
          s.push_back(prev);
          break;
        }
      }
      s.push_back(points[curr++]);
    }

    int size = s.size();

    cout << size << '\n';
    for (int i = 0; i < size; i++) cout << s[i].x << ' ' << s[i].y << '\n';
  }
}