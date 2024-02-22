#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
  string s, t;

  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < t.length(); j++) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }
  cout << dp[s.length()][t.length()];
}