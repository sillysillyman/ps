#include <algorithm>
#include <cstdio>

int tetra[121];
int dp[300'001];

int main() {
  int N;
  scanf("%d", &N);

  int k = 1;
  for (int i = 1; i < 121; i++) tetra[i] = tetra[i - 1] + k++;
  for (int i = 1; i < 121; i++) tetra[i] += tetra[i - 1];

  dp[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (std::binary_search(tetra, tetra + 121, i))
      dp[i] = 1;
    else {
      dp[i] = N;
      for (int j = 1; tetra[j] < i; j++) {
        dp[i] = std::min(dp[i], dp[tetra[j]] + dp[i - tetra[j]]);
        if (dp[i] == 2) break;
      }
    }
  }

  printf("%d", dp[N]);
}