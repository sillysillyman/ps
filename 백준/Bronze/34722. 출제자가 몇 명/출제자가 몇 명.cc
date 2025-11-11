#include <cstdio>

int n, N, s, c, a, r;

int main() {
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d%d%d", &s, &c, &a, &r);
    n += s > 999 || c > 1599 || a > 1499 || (!!~r && r < 31);
  }
  printf("%d", n);
}