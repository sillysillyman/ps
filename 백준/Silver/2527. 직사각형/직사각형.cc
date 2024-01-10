#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

struct Rectangle {
  Point p, q;
};

char classify(Rectangle& r1, Rectangle& r2) {
  if ((r1.q.x == r2.p.x && r1.p.y == r2.q.y) ||
      (r1.q.x == r2.p.x && r1.q.y == r2.p.y) ||
      (r1.p.x == r2.q.x && r1.q.y == r2.p.y) ||
      (r1.p.x == r2.q.x && r1.p.y == r2.q.y)) return 'c';
  if ((r1.p.x == r2.q.x) || (r1.q.x == r2.p.x)) {
    if ((r1.p.y <= r2.q.y && r1.q.y >= r2.p.y) ||
        (r2.p.y <= r1.q.y && r2.q.y >= r1.p.y)) return 'b';
    else return 'd';
  } else if ((r1.p.y == r2.q.y) || (r1.q.y == r2.p.y)) {
    if ((r1.p.x <= r2.q.x && r1.q.x >= r2.p.x) ||
        (r2.p.x <= r1.q.x && r2.q.x >= r1.p.x)) return 'b';
    else return 'd';
  }
  if (r1.q.x < r2.p.x || r1.p.x > r2.q.x || r1.p.y > r2.q.y || r1.q.y < r2.p.y) return 'd';
  return 'a';
}

int main() {
  Point p, q, r, s;

  for (int i = 0; i < 4; i++) {
    cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> s.x >> s.y;

    Rectangle r1{p, q};
    Rectangle r2{r, s};
  
    cout << classify(r1, r2) << '\n';
  }
}