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
  if (n == 0)
    printf("0");
  else if (n == 1)
    printf("1");
  else
    printf("%lld", next);
}