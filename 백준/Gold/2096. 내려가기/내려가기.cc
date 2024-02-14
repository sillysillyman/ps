#include <algorithm>
#include <iostream>

using namespace std;

int min_dp[3];
int max_dp[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int a, b, c, i = 0; i < N; i++) {
    cin >> a >> b >> c;
    if (i == 0) {
      min_dp[0] = a, min_dp[1] = b, min_dp[2] = c;
      max_dp[0] = a, max_dp[1] = b, max_dp[2] = c;
      continue;
    }

    int min_prev_a = min_dp[0], min_prev_b = min_dp[1], min_prev_c = min_dp[2];
    int max_prev_a = max_dp[0], max_prev_b = max_dp[1], max_prev_c = max_dp[2];

    min_dp[0] = min(min_prev_a, min_prev_b) + a;
    min_dp[1] = min(min_prev_a, min(min_prev_b, min_prev_c)) + b;
    min_dp[2] = min(min_prev_b, min_prev_c) + c;
    max_dp[0] = max(max_prev_a, max_prev_b) + a;
    max_dp[1] = max(max_prev_a, max(max_prev_b, max_prev_c)) + b;
    max_dp[2] = max(max_prev_b, max_prev_c) + c;
  }
  cout << *max_element(max_dp, max_dp + 3) << ' '
       << *min_element(min_dp, min_dp + 3);
}