#include <iostream>

using namespace std;

int dp[1'001][1'001];

int main() {
  string s, t;

  cin >> s >> t;

  int s_len = s.length();
  int t_len = t.length();
  for (int i = 0; i < s_len; i++) {
    for (int j = 0; j < t_len; j++) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  int i = s_len, j = t_len;
  string lcs;

  while (i && j) {
    if (s[i - 1] == t[j - 1]) {
      lcs = s[i - 1] + lcs;
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1])
      --i;
    else
      --j;
  }
  cout << dp[s_len][t_len] << '\n' << lcs;
}