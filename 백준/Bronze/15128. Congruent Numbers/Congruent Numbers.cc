#include <cstdio>

int main() {
  long long a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  printf("%d", !(a * c % (2 * b * d)));
}