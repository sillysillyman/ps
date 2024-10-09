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
  queue<pair<int, int>> q;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &graph[i][j]);
      if (graph[i][j]) {
        q.push({i, j});
        graph[i][j] = 0;
      } else
        graph[i][j] = -1;
    }
  }

  while (!q.empty()) {
    auto [x, y] = q.front();

    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];

      if (0 <= nx && nx < N && 0 <= ny && ny < M && graph[nx][ny] == -1) {
        graph[nx][ny] = graph[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }

  int max_dist = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) max_dist = max(max_dist, graph[i][j]);
  printf("%d", max_dist);
}