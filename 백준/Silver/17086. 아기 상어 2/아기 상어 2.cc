#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int N, M, max_safe_dist = 0;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[50][50];
int graph[50][50];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int bfs(int x, int y) {
  queue<tuple<int, int, int>> q;

  q.push({x, y, 0});
  visited[x][y] = true;
  while (!q.empty()) {
    auto [x, y, safe_dist] = q.front();

    if (graph[x][y]) return safe_dist;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i], ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny]) {
        if (graph[nx][ny]) return safe_dist + 1;
        visited[nx][ny] = true;
        q.push({nx, ny, safe_dist + 1});
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &graph[i][j]);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      fill(&visited[0][0], &visited[N - 1][M], false);
      max_safe_dist = max(max_safe_dist, bfs(i, j));
    }
  printf("%d", max_safe_dist);
}