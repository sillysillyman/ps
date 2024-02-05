#include <iostream>

using namespace std;

int dp[4000][4000];

int main() {
  int len = 0;
  string s, t;

  cin >> s >> t;
  fill(&dp[0][0], &dp[s.length() - 1][t.length()], 0);
  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < t.length(); j++) {
      if (s[i] == t[j]) {
        dp[i][j] = 1;
        if (i > 0 && j > 0) dp[i][j] += dp[i - 1][j - 1];
      }
      len = max(len, dp[i][j]);
    }
  }
  cout << len;
}