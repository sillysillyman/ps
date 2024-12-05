#include <cstdio>

using ll = long long;

const int MOD = 1e9;
ll dp[101][10][1 << 10];

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 1; i < 10; i++) dp[1][i][1 << i] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < (1 << 10); k++) {
        if (j > 0) {
          dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k];
          dp[i][j][k | (1 << j)] %= MOD;
        }
        if (j < 9) {
          dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k];
          dp[i][j][k | (1 << j)] %= MOD;
        }
      }
    }
  }

  ll cnt = 0;
  for (int i = 0; i < 10; i++) {
    cnt += dp[N][i][(1 << 10) - 1];
    cnt %= MOD;
  }
  printf("%lld", cnt);
}