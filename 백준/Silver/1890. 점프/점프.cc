#include <iostream>

using namespace std;

int board[100][100];
long long dp[100][100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> board[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == 0 && j == 0) dp[i][j] = 1;
      for (int k = 1; k < N; k++) {
        if (i - k < 0) break;
        if (board[i - k][j] == k) dp[i][j] += dp[i - k][j];
      }
      for (int k = 1; k < N; k++) {
        if (j - k < 0) break;
        if (board[i][j - k] == k) dp[i][j] += dp[i][j - k];
      }
    }
  }
  cout << dp[N - 1][N - 1];
}