#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct Point {
  double x, y, z;
};

Point points[100'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y >> points[i].z;
  nth_element(points, points + k - 1, points + n,
              [](const Point& p1, const Point& p2) {
                return p1.x * p1.x + p1.y * p1.y + p1.z * p1.z <
                       p2.x * p2.x + p2.y * p2.y + p2.z * p2.z;
              });

  Point p = points[k - 1];
  cout << fixed;
  cout.precision(6);
  cout << sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}