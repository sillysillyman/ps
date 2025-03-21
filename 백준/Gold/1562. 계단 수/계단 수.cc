#include <cstdio>

const int MOD = 1e9;
const int SHIFT = 1 << 10;
long long dp[101][10][SHIFT];

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 1; i < 10; i++) dp[1][i][1 << i] = 1;

  for (int i = 2; i <= N; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < SHIFT; k++) {
        if (j > 0)
          dp[i][j][k | (1 << j)] =
              (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % MOD;
        if (j < 9)
          dp[i][j][k | (1 << j)] =
              (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % MOD;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < 10; i++) cnt = (cnt + dp[N][i][SHIFT - 1]) % MOD;
  printf("%d", cnt);
}