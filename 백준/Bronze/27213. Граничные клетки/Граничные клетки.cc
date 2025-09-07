#include <cstdio>

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  printf("%d", m == 1 || n == 1 ? m * n: 2 * (--m + --n));
}