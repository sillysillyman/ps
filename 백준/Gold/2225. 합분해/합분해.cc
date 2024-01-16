#include <iostream>

using namespace std;

const int MOD = 1000000000;
int dp[400][201];

int combination(int n, int r) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= r; j++) {
      if (i == j || j == 0) dp[i][j] = 1;
      else dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i - 1][j - 1] % MOD)) % MOD;
    }
  }
  return dp[n][r];
}

int combination_with_repetition(int n, int r) { return combination(n + r - 1, r); }

int main() {
  int N, K;

  cin >> N >> K;
  cout << combination_with_repetition(K, N);
}