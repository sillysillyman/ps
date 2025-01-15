#include <cstdio>

struct Point {
  int x, y;

  Point operator+(const Point& other) const {
    return {x + other.x, y + other.y};
  }
};

int pairing(Point p) { return (p.x + p.y - 2) * (p.x + p.y - 1) / 2 + p.x; }

Point unpairing(int z) {
  int s = 2;
  while (s * (s - 1) / 2 < z) s++;
  int x = z - (s - 2) * (s - 1) / 2;
  return {x, s - x};
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int p, q;
    scanf("%d%d", &p, &q);
    printf("%d\n", pairing(unpairing(p) + unpairing(q)));
  }
}