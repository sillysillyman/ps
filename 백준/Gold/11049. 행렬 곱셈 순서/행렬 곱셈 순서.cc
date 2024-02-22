#include <iostream>

using namespace std;

const int INF = ~(1 << 31);
pair<int, int> shape[501];
int dp[501][501];

int main() {
  int N;

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> shape[i].first >> shape[i].second;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = 1; i + j <= N; j++) {
      dp[j][i + j] = INF;
      for (int k = j; k <= i + j; k++) {
        dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] +
                                             shape[j].first * shape[k].second *
                                                 shape[i + j].second);
      }
    }
  }
  cout << dp[1][N];
}