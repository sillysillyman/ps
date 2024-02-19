#include <iostream>

using namespace std;

const int MAX = 1'000'000'000;
int dp[101][101];

int main() {
  int N, M, K;

  cin >> N >> M >> K;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= M; j++) {
      if (i == 0 || j == 0) dp[i][j] = 1;
      else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      if (dp[i][j] >= MAX) dp[i][j] = MAX;
    }
  }
  if (dp[N][M] < K) {
    cout << -1;
    return 0;
  }
  while (true) {
    if (N == 0) {
      while (M > 0) {
        cout << 'z';
        M--;
      }
    }
    if (M == 0) {
      while (N > 0) {
        cout << 'a';
        N--;
      }
    }
    if (N == 0 && M == 0) break;
    if (K <= dp[N - 1][M]) {
      cout << 'a';
      N--;
    } else {
      cout << 'z';
      K -= dp[N - 1][M];
      M--;
    }
  }
}