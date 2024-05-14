#include <iostream>

using namespace std;

const int MOD = 1'000'000'007;
int dp[1'000][1'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> dp[i][j];
  }
  for (int i = N - 2; i >= 0; i--) {
    for (int j = 0; j < M; j++) {
      if (!dp[i][j]) continue;
      dp[i][j] = 0;
      if (j > 0) dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % MOD;
      dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
      if (j < M - 1) dp[i][j] = (dp[i][j] + dp[i + 1][j + 1]) % MOD;
    }
  }

  int sum = 0;

  for (int j = 0; j < M; j++) {
    sum += dp[0][j];
    sum %= MOD;
  }
  cout << sum;
}