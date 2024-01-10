#include <iostream>

using namespace std;

struct Point {
  long long x, y;

  bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

// (p.x, q.y)----(q.x, q.y)
// |                      |
// |                      | 
// (p.x, p.y)----(q.x, p.y)
struct Rectangle {
  Point p, q;
};

string classify(Rectangle& r1, Rectangle& r2) {
  if ((Point{r1.q.x, r1.p.y} == Point{r2.p.x, r2.q.y}) ||
      (r1.q == r2.p) ||
      (Point{r1.p.x, r1.q.y} == Point{r2.q.x, r2.p.y}) ||
      (r1.p == r2.q)) return "POINT";
  if (r1.p.x == r2.q.x || r1.q.x == r2.p.x) {
    if ((r1.p.y <= r2.q.y && r1.q.y >= r2.p.y) ||
        (r2.p.y <= r1.q.y && r2.q.y >= r1.p.y)) return "LINE";
    else return "NULL";
  } else if (r1.p.y == r2.q.y || r1.q.y == r2.p.y) {
    if ((r1.p.x <= r2.q.x && r1.q.x >= r2.p.x) ||
        (r2.p.x <= r1.q.x && r2.q.x >= r1.p.x)) return "LINE";
    else return "NULL";
  }
  if (r1.p.x > r2.q.x || r1.q.x < r2.p.x ||
      r1.p.y > r2.q.y || r1.q.y < r2.p.y) return "NULL";
  return "FACE";
}

int main() {
  Rectangle r1, r2;

  cin >> r1.p.x >> r1.p.y >> r1.q.x >> r1.q.y;
  cin >> r2.p.x >> r2.p.y >> r2.q.x >> r2.q.y;
  cout << classify(r1, r2);
}