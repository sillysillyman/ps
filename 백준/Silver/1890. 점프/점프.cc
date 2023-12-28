#include <iostream>

using namespace std;

int graph[100][100];
long long dp[100][100];

int main() {
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> graph[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == 0 && j == 0) dp[i][j] = 1;
      for (int k = 1; k < N; k++) {
        if (i - k < 0) break;
        if (graph[i - k][j] == k) dp[i][j] += dp[i - k][j];
      }
      for (int k = 1; k < N; k++) {
        if (j - k < 0) break;
        if (graph[i][j - k] == k) dp[i][j] += dp[i][j - k];
      }
    }
  }
//   cout << '\n';
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) cout << dp[i][j] << ' ';
//     cout << '\n';
//   }
  cout << dp[N - 1][N - 1];
}
// 2 3 3 1
// 1 2 1 3
// 1 2 3 1
// 3 1 1 0

// 1 0 1 0
// 0 0 0 0
// 1 1 0 1
// 1 0 2 3