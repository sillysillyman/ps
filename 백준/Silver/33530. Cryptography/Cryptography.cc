#include <cstdio>

bool is_prime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}

int main() {
  long long n;
  scanf("%lld", &n);
  printf("%s", is_prime(n) ? "SAFE" : "BROKEN");
}