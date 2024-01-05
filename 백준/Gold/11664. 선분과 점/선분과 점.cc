#include <cmath>
#include <iostream>

using namespace std;

struct Point {
  long long x, y, z;
};

double distance(Point p, Point q) {
  return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y) +
              (p.z - q.z) * (p.z - q.z));
}

int dot_product(Point& p, Point& q, Point& r) {
  Point u, v;

  u = {p.x - q.x, p.y - q.y, p.z - q.z};
  v = {r.x - q.x, r.y - q.y, r.z - q.z};
  return u.x * v.x + u.y * v.y + u.z * v.z;
}

Point cross_product(Point& p, Point& q, Point& r) {
  Point u, v;

  u = {p.x - q.x, p.y - q.y, p.z - q.z};
  v = {r.x - q.x, r.y - q.y, r.z - q.z};
  return Point{u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
               u.x * v.y - u.y * v.x};
}

int main() {
  Point A, B, C;

  cin >> A.x >> A.y >> A.z >> B.x >> B.y >> B.z >> C.x >> C.y >> C.z;
  cout << fixed;
  cout.precision(10);
  if (dot_product(C, A, B) >= 0 && dot_product(C, B, A) >= 0)
    cout << distance({0, 0, 0}, cross_product(C, A, B)) / distance(A, B);
  else if (dot_product(C, A, B) < 0)
    cout << distance(A, C);
  else if (dot_product(C, B, A))
    cout << distance(B, C);
}