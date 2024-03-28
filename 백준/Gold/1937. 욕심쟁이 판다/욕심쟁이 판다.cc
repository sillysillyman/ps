#include <iostream>

using namespace std;

int n;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int dp[500][500];
int graph[500][500];

bool is_inside(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

int dfs(int x, int y) {
  if (dp[x][y] != -1) return dp[x][y];
  dp[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_inside(nx, ny) && graph[nx][ny] > graph[x][y])
      dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
  }
  return dp[x][y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int depth = 0;

  cin >> n;
  fill(&dp[0][0], &dp[n - 1][n], -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> graph[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      depth = max(depth, dfs(i, j));
    }
  }
  cout << depth;
}