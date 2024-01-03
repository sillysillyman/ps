#include <iostream>

using namespace std;

int dp[100][100001];
pair<int, int> knapsack[100];

int main() {
  int N, K;

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int W, V;

    cin >> W >> V;
    knapsack[i] = {W, V};
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= K; j++) {
      if (j == 0) {
        dp[i][j] = 0;
        continue;
      }
      if (i == 0) {
        if (knapsack[i].first <= j) dp[i][j] = knapsack[i].second;
        else dp[i][j] = 0;
      } else {
        if (knapsack[i].first <= j) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - knapsack[i].first] + knapsack[i].second);
        else dp[i][j] = dp[i - 1][j];
      }
    }
  }
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j <= K; j++) {
//       cout << dp[i][j] << ' ';
//     }
//     cout << '\n';
//   }
  cout << dp[N - 1][K];
}