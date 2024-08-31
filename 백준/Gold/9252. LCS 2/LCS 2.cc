#include <algorithm>
#include <cstdio>
#include <cstring>

const int MAX = 1'000;
int dp[MAX + 1][MAX + 1];

int main() {
  char s[MAX + 1], t[MAX + 1], lcs[MAX + 1];

  scanf("%s%s", s, t);

  int s_len = strlen(s);
  int t_len = strlen(t);
  for (int i = 0; i < s_len; i++) {
    for (int j = 0; j < t_len; j++) {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  int idx = dp[s_len][t_len];
  lcs[idx] = '\0';
  for (int i = s_len, j = t_len; i && j;) {
    if (s[i - 1] == t[j - 1]) {
      lcs[--idx] = s[i - 1];
      --i;
      --j;
    } else if (dp[i - 1][j] > dp[i][j - 1])
      --i;
    else
      --j;
  }
  printf("%d\n%s", dp[s_len][t_len], lcs);
}