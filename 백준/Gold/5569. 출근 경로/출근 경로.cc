#include <iostream>

using namespace std;

const int MOD = 100'000;
int dp[100][100][2][2];

int main() {
  int w, h;

  cin >> w >> h;
  for (int i = 0; i < h; i++) dp[i][0][0][0] = 1;
  for (int i = 0; i < w; i++) dp[0][i][1][1] = 1;
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      dp[i][j][0][0] += dp[i - 1][j][0][0] + dp[i - 1][j][0][1];
      dp[i][j][0][0] %= MOD;
      dp[i][j][0][1] += dp[i - 1][j][1][1];
      dp[i][j][0][1] %= MOD;
      dp[i][j][1][0] += dp[i][j - 1][0][0];
      dp[i][j][1][0] %= MOD;
      dp[i][j][1][1] += dp[i][j - 1][1][0] + dp[i][j - 1][1][1];
      dp[i][j][1][1] %= MOD;
    }
  }
  cout << (dp[h - 1][w - 1][0][0] + dp[h - 1][w - 1][0][1] +
           dp[h - 1][w - 1][1][0] + dp[h - 1][w - 1][1][1]) %
              MOD;
}