#include <cstdio>

int main() {
  long long a, b;
  scanf("%lld%lld", &a, &b);
  if (a < 3) a = 4;
  if (b < 3) return printf("0"), 0;
  a = (++a / 2) * 2;
  b = (b / 2) * 2;
  b = (b - a) / 2 + 1;
  printf("%lld", b * (a + b - 1));
}