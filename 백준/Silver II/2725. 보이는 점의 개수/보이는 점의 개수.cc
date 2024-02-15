#include <iostream>

using namespace std;

int dp[1001];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  int C, N;

  cin >> C;
  dp[1] = 1;
  for (int x = 1; x <= 1000; x++) {
    for (int y = 1; y <= x; y++) {
      if (gcd(x, y) == 1) dp[x]++;
    }
  }
  for (int i = 2; i <= 1000; i++) dp[i] += dp[i - 1];
  while (C--) {
    cin >> N;
    cout << 2 * dp[N] - 1 << '\n';
  }
}