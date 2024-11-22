#include <cstdio>
#include <set>

using namespace std;

struct Point {
  double x, y;

  bool operator<(const Point& other) const {
    return x == other.x ? y < other.y : x < other.x;
  }

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }

  Point operator-(const Point& other) const {
    return {x - other.x, y - other.y};
  }
};

int main() {
  int c;

  scanf("%d", &c);
  while (c--) {
    int n;
    double x_sum = 0, y_sum = 0;
    set<Point> points;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      double x, y;

      scanf("%lf%lf", &x, &y);
      x_sum += x;
      y_sum += y;
      points.insert({x, y});
    }

    bool flag = true;
    Point p = {2 * x_sum / n, 2 * y_sum / n};
    for (auto& point : points) {
      if (points.find(p - point) == points.end()) {
        flag = false;
        break;
      }
    }
    printf("%s\n", flag ? "yes" : "no");
  }
}