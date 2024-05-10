#include <vector>

using namespace std;

const int MOD = 1'234'567;

int solution(int n) {
  vector<int> dp(n + 1);

  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
  return dp[n];
}