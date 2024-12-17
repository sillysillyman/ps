#include <cstdio>

long long dp[81];

int main() {
  int N;

  scanf("%d", &N);
  dp[1] = 1;
  for (int i = 2; i <= N; i++) dp[i] = dp[i - 2] + dp[i - 1];
  printf("%lld", N == 1 ? 4
               : N == 2 ? 6
               : dp[N - 3] + 2 * dp[N - 2] + 2 * dp[N - 1] + 3 * dp[N]);
}