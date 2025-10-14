#include <cstdio>

int main() {
  int x, y, z, s;
  scanf("%d%d%d", &x, &y, &z);
  s = 25 * (x + y) + 50 * z;
  printf(s >= 9e3 ? "A" : s >= 8e3 ? "B" : s >= 7e3 ? "C" : s >= 6e3 ? "D" : "F");
}