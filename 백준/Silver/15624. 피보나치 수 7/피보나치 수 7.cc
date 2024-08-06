#include <cstdio>

const int MOD = 1'000'000'007;

int main() {
  int n;
  long long prev = 0, curr = 1, next;

  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    next = (prev + curr) % MOD;
    prev = curr;
    curr = next;
  }
  printf("%lld", next);
}