#include <iostream>

using namespace std;

int dp[100'002];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> dp[i];
    dp[i] += dp[i - 1];
  }
  while (M--) {
    int i, j;

    cin >> i >> j;
    cout << dp[j] - dp[i - 1] << '\n';
  }
}