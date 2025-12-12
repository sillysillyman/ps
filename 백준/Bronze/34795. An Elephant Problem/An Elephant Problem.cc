#include <cstdio>

int main() {
  int m, d;
  scanf("%d%d", &m, &d);
  printf("%d", d / m + !!(d % m));
}