#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

string dp[101][101];

string add(string s, string t) {
  if (s.length() < t.length()) swap(s, t);

  for (int t_len = t.length(), i = 0; i < s.length() - t_len; i++) t = '0' + t;

  int carry = 0;
  string res;
  for (int i = s.length() - 1; i >= 0; i--) {
    int digit = (s[i] - '0') + (t[i] - '0') + carry;
    res = (char)(digit % 10 + '0') + res;
    carry = digit / 10;
  }

  if (carry) res = '1' + res;

  return res;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i <= n; i++) dp[i][0] = "1";
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) dp[i][j] = add(dp[i - 1][j], dp[i - 1][j - 1]);
  printf("%s", dp[n][m].c_str());
}