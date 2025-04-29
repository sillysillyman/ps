#include <algorithm>
#include <cstdio>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (a > b) std::swap(a, b);
  if (b > c) std::swap(b, c);
  printf("%d", a == b && b == c ? 2 : c * c == a * a + b * b ? 1 : 0);
}