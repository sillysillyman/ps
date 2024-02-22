#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, max_area = 0;

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string row;

    cin >> row;
    for (int j = 1; j <= m; j++) {
      dp[i][j] = row[j - 1] - '0';
      if (dp[i][j])
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      max_area = max(max_area, dp[i][j] * dp[i][j]);
    }
  }
  cout << max_area;
}