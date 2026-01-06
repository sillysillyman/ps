#include <cstdio>
#include <numeric>

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  long long x = std::lcm(a, b);
  x = n / x;
  printf("%lld %lld %lld", n / a - x, n / b - x, x);
}