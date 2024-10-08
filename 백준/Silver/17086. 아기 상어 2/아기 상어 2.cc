#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  int N, M;

  scanf("%d%d", &N, &M);

  vector<vector<int>> graph(N, vector<int>(M));
  vector<vector<int>> dist(N, vector<int>(M, -1));
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j]) {
        q.push({i, j});
        dist[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();

    q.pop();
    for (int d = 0; d < 8; d++) {
      int nx = x + dx[d], ny = y + dy[d];

      if (0 <= nx && nx < N && 0 <= ny && ny < M && dist[nx][ny] == -1) {
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  int max_dist = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) max_dist = max(max_dist, dist[i][j]);
  printf("%d", max_dist);
}