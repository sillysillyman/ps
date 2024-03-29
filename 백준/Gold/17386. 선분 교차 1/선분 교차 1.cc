#include <iostream>

using namespace std;
using ll = long long;

struct Point {
  ll x, y;
};

struct Line {
  Point p, q;
};

int ccw(Point p, Point q, Point r) {
  ll cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);

  if (cross_product) return cross_product / abs(cross_product);
  return 0;
}

int main() {
  Line L1, L2;

  cin >> L1.p.x >> L1.p.y >> L1.q.x >> L1.q.y;
  cin >> L2.p.x >> L2.p.y >> L2.q.x >> L2.q.y;
  cout << (ccw(L1.p, L1.q, L2.p) * ccw(L1.p, L1.q, L2.q) < 0 &&
           ccw(L2.p, L2.q, L1.p) * ccw(L2.p, L2.q, L1.q) < 0);
}