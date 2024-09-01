#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;
using ll = long long;

struct Point {
  int x, y;
};

ll cross_product(Point origin, Point p, Point q) {
  Point u = {p.x - origin.x, p.y - origin.y};
  Point v = {q.x - origin.x, q.y - origin.y};

  return (ll)u.x * v.y - (ll)v.x * u.y;
}

int main() {
  int N;
  double area = 0;

  scanf("%d", &N);

  Point p;
  vector<Point> points(N);

  for (int i = 0; i < N; i++) {
    scanf("%d%d", &p.x, &p.y);
    points[i] = p;
  }
  for (int i = 1; i < N - 1; i++)
    area += cross_product(points[0], points[i + 1], points[i]) / 2.0;
  printf("%.1lf", abs(area));
}