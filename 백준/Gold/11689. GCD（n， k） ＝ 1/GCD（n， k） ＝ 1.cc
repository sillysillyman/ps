#include <cstdio>

int main() {
  long long n;
  scanf("%lld", &n);

  long long ans = n;
  for (long long i = 2; i * i <= n; i++) {
    if (!(n % i)) ans = ans / i * (i - 1);
    while (!(n % i)) n /= i;
  }
  if (n > 1) ans = ans / n * (n - 1);

  printf("%lld", ans);
}