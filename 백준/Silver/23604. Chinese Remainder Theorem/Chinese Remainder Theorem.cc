#include <cstdio>
#include <numeric>

long long arr[100'000];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);
  for (int i = 0; i < n; i++) {
    long long b;
    scanf("%lld", &b);
    arr[i] -= b;
  }

  long long m = arr[0];
  for (int i = 1; i < n; i++) m = std::gcd(m, arr[i]);
  printf("%lld", m);
}