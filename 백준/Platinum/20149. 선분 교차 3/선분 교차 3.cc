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
  if (ll cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
      cross_product)
    return cross_product / abs(cross_product);
  return 0;
}

bool is_point_on_line(Point p, Line l) {
  if (ccw(p, l.p, l.q)) return false;
  if (l.p.x > l.q.x || (l.p.x == l.q.x && l.p.y > l.q.y)) swap(l.p, l.q);
  return l.p.x == l.q.x ? l.p.y <= p.y && p.y <= l.q.y
                        : l.p.x <= p.x && p.x <= l.q.x;
}

bool do_lines_overlap(Line l1, Line l2) {
  if (l1.p.x == l1.q.x || l2.p.x == l2.q.x) {
    if (l1.p.x == l1.q.x && l2.p.x == l2.q.x) {
      if (l1.p.y > l2.p.y) swap(l1.p, l1.q);
      if (l2.p.y > l2.q.y) swap(l2.p, l2.q);
      return l1.p.x == l2.p.x && l1.p.y < l2.q.y && l2.p.y < l1.q.y;
    }
    return false;
  }
  if (!ccw(l1.p, l1.q, l2.p) && !ccw(l1.p, l1.q, l2.q)) {
    if (l1.p.x > l1.q.x) swap(l1.p, l1.q);
    if (l2.p.x > l2.q.x) swap(l2.p, l2.q);
    return l1.p.x < l2.q.x && l2.p.x < l1.q.x;
  }
  return false;
}

int main() {
  Line L1, L2;

  cin >> L1.p.x >> L1.p.y >> L1.q.x >> L1.q.y;
  cin >> L2.p.x >> L2.p.y >> L2.q.x >> L2.q.y;
  if (do_lines_overlap(L1, L2))
    cout << 1;
  else if (is_point_on_line(L1.p, L2))
    cout << 1 << '\n' << L1.p.x << ' ' << L1.p.y;
  else if (is_point_on_line(L1.q, L2))
    cout << 1 << '\n' << L1.q.x << ' ' << L1.q.y;
  else if (is_point_on_line(L2.p, L1))
    cout << 1 << '\n' << L2.p.x << ' ' << L2.p.y;
  else if (is_point_on_line(L2.q, L1))
    cout << 1 << '\n' << L2.q.x << ' ' << L2.q.y;
  else if (ccw(L1.p, L1.q, L2.p) * ccw(L1.p, L1.q, L2.q) < 0 &&
           ccw(L2.p, L2.q, L1.p) * ccw(L2.p, L2.q, L1.q) < 0) {
    ll A1 = L1.q.y - L1.p.y;
    ll A2 = L2.q.y - L2.p.y;
    ll B1 = L1.p.x - L1.q.x;
    ll B2 = L2.p.x - L2.q.x;
    ll C1 = A1 * L1.p.x + B1 * L1.p.y;
    ll C2 = A2 * L2.p.x + B2 * L2.p.y;

    cout << fixed;
    cout.precision(9);
    cout << 1 << '\n'
         << (double)(C1 * B2 - B1 * C2) / (A1 * B2 - B1 * A2) << ' '
         << (double)(A1 * C2 - C1 * A2) / (A1 * B2 - B1 * A2);
  } else
    cout << 0;
}