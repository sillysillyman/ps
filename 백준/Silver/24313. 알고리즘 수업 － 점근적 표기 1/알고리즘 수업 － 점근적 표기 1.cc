#include <cstdio>

int main() {
  int a1, a0, c, n0;

  scanf("%d%d%d%d", &a1, &a0, &c, &n0);
  printf("%d", a1 <= c && a0 <= (c - a1) * n0);
}