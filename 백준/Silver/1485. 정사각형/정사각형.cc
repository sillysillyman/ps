#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
  long long x, y;

  bool operator==(const Point& p) const { return (x == p.x) && (y == p.y); }
  bool operator<(const Point& p) const {
    return x < p.x || (x == p.x && y < p.y);
  }
};

int main() {
  int T;

  cin >> T;
  while (T--) {
    Point points[4];
    Point a, b, c, d;

    for (int i = 0; i < 4; i++) cin >> points[i].x >> points[i].y;
    sort(points, points + 4);
    a = points[0], b = points[1], c = points[2], d = points[3];
    if (((a.x - d.x) * (a.x - d.x) + (a.y - d.y) * (a.y - d.y) ==
         (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y)) &&
        ((a.y - d.y) * (b.y - c.y) + (a.x - d.x) * (b.x - c.x) == 0))
      cout << "1\n";
    else
      cout << "0\n";
  }
}