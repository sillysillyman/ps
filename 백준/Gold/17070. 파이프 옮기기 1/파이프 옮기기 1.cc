#include <cstdio>

int graph[17][17];
int dp[17][17][3];

int main() {
  int N;

  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) scanf("%d", &graph[i][j]);

  dp[1][2][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (graph[i][j]) continue;
      dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
      dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
      if (!(graph[i - 1][j] || graph[i][j - 1]))
        dp[i][j][2] +=
            dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
    }
  }
  printf("%d", dp[N][N][0] + dp[N][N][1] + dp[N][N][2]);
}