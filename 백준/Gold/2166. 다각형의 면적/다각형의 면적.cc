#include <iostream>
#include <vector>

using namespace std;

struct point {
  int x, y;
};

long long cross_product(point origin, point p, point q) {
  point u = {p.x - origin.x, p.y - origin.y};
  point v = {q.x - origin.x, q.y - origin.y};

  return (long long)u.x * v.y - (long long)v.x * u.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  double area = 0;

  cin >> N;

  point p;
  vector<point> points(N);

  for (int i = 0; i < N; i++) {
    cin >> p.x >> p.y;
    points[i] = p;
  }
  cout << fixed;
  cout.precision(1);
  for (int i = 1; i < N - 1; i++)
    area += cross_product(points[0], points[i + 1], points[i]) / 2.0;
  cout << abs(area);
}