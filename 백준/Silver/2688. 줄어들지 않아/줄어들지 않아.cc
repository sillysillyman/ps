#include <iostream>

using namespace std;

long long dp[65][10];

int main() {
  int T, n;

  for (int i = 1; i < 65; i++) {
    for (int j = 0; j < 10; j++) {
      if (i == 1 || j == 0)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  cin >> T;
  while (T--) {
    cin >> n;

    long long sum = 0;

    for (int i = 0; i < 10; i++) sum += dp[n][i];
    cout << sum << '\n';
  }
}