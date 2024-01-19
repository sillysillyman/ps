#include <iostream>

using namespace std;

pair<int, int> apps[100];
int dp[101][100001];

int main() {
  int N, M;
  int max_cost = 0;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> apps[i].first;
  for (int i = 1; i <= N; i++) {
    cin >> apps[i].second;
    max_cost += apps[i].second;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= max_cost; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j - apps[i].second >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - apps[i].second] + apps[i].first);
    }
  }
  for (int i = 0; i <= max_cost; i++) {
    if (dp[N][i] >= M) {
      cout << i;
      break;
    }
  }
}