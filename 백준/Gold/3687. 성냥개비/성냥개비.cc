#include <algorithm>
#include <cstdio>

int arr[9] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
long long dp[101];

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i < 9; i++) dp[i] = arr[i];
  dp[6] = 6;
  for (int i = 9; i < 101; i++) {
    dp[i] = ~(1LL << 63);
    for (int j = 2; j < 8; j++)
      dp[i] = std::min(dp[i], 10 * dp[i - j] + arr[j]);
  }

  while (t--) {
    int n;
    scanf("%d", &n);

    printf("%lld ", dp[n]);
    if (n & 1) {
      printf("7");
      for (int i = 0; i < (n - 3) / 2; i++) printf("1");
    } else {
      for (int i = 0; i < n / 2; i++) printf("1");
    }
    printf("\n");
  }
}