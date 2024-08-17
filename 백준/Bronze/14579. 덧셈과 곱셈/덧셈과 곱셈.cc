#include <cstdio>

const int MOD = 14'579;

int main() {
  int a, b, res = 1;

  scanf("%d%d", &a, &b);
  for (int i = a; i <= b; i++) {
    res *= (i * (i + 1) / 2) % MOD;
    res %= MOD;
  }
  printf("%d", res);
}