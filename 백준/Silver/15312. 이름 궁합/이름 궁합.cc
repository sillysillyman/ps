#include <iostream>

using namespace std;

int strokes[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2,
                   2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int dp[4'000];

int main() {
  int len;
  string A, B;

  cin >> A >> B;
  len = A.length();
  for (int i = 0; i < len; i++) {
    dp[2 * i] = strokes[A[i] - 'A'];
    dp[2 * i + 1] = strokes[B[i] - 'A'];
  }
  // for (int k = 0; k < 2 * len; k++) cout << dp[k] << ' ';
  // cout << '\n';
  for (int i = 2 * len; i > 2; i--) {
    for (int j = 0; j < i - 1; j++) dp[j] = (dp[j] + dp[j + 1]) % 10;
    // for (int k = 0; k < 2 * len; k++) cout << dp[k] << ' ';
    // cout << '\n';
  }
  cout << dp[0] << dp[1];
}
// 0 0 0 0 0 0 0 0
//  0 0 0 0 0 0 0
//   0 0 0 0 0 0
//    0 0 0 0 0
//     0 0 0 0
//      0 0 0
//       0 0