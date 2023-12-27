#include <iostream>

using namespace std;

int stickers[2][100000];
int dp[2][100000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int n;

    cin >> n;
    fill(&dp[0][0], &dp[1][100000], 0);
    for (int i = 0; i < n; i++) cin >> stickers[0][i];
    for (int i = 0; i < n; i++) cin >> stickers[1][i];
    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];
    if (n == 1) {
      cout << max(dp[0][0], dp[1][0]) << '\n';
      continue;
    }
    dp[0][1] = dp[1][0] + stickers[0][1];
    dp[1][1] = dp[0][0] + stickers[1][1];
    for (int i = 2; i < n; i++) {
      dp[0][i] = max(dp[1][i - 1] + stickers[0][i], max(dp[0][i - 2], dp[1][i - 2]) + stickers[0][i]);
      dp[1][i] = max(dp[0][i - 1] + stickers[1][i], max(dp[0][i - 2], dp[1][i - 2]) + stickers[1][i]);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
  }
}