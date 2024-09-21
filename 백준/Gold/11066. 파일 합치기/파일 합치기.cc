#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int INF = 1'252'500'000;
int prefix_sum[501];
int dp[501][501];

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int K;

    scanf("%d", &K);
    for (int i = 1; i <= K; i++) scanf("%d", &prefix_sum[i]);
    for (int i = 1; i <= K; i++) prefix_sum[i] += prefix_sum[i - 1];
    fill(&dp[0][0], &dp[K][K + 1], 0);
    for (int len = 2; len <= K; len++) {
      for (int i = 1; i + len - 1 <= K; i++) {
        int j = i + len - 1;
        dp[i][j] = INF;
        for (int k = i; k < j; k++)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix_sum[j] -
                                       prefix_sum[i - 1]);
      }
    }
    printf("%d\n", dp[1][K]);
  }
}