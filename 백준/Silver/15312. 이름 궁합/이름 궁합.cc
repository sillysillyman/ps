#include <iostream>

using namespace std;

int strokes[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2,
                   2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int dp[4'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int len;
  string A, B;

  cin >> A >> B;
  len = A.length();
  for (int i = 0; i < len; i++) {
    dp[2 * i] = strokes[A[i] - 'A'];
    dp[2 * i + 1] = strokes[B[i] - 'A'];
  }
  for (int i = 2 * len; i > 2; i--) {
    for (int j = 0; j < i - 1; j++) dp[j] = (dp[j] + dp[j + 1]) % 10;
  }
  cout << dp[0] << dp[1];
}