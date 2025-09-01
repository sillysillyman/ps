#include <cstdio>

int main() {
  int a, b, c, d, x;
  scanf("%d%d%d%d%d%*d%*d", &a, &b, &c, &d, &x);
  printf("%d", x == a ? 1 : x == b ? 2 : x == c ? 3 : x == d ? 4 : 0);
}