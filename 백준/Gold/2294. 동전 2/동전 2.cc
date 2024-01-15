#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10001;
int dp[10001];

int main() {
  int n, k;

  cin >> n >> k;

  vector<int> coins(n);

  for (int i = 0; i < n; i++) cin >> coins[i];
  fill(dp + 1, dp + 10001, MAX);
  dp[0] = 0;
  for (int coin : coins) {
    for (int i = coin; i <= k; i++) dp[i] = min(dp[i], dp[i - coin] + 1);
  }
  if (dp[k] == MAX) cout << -1;
  else cout << dp[k];
}