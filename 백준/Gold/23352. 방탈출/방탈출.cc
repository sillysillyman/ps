#include <algorithm>
#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int graph[50][50];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

pair<int, int> bfs(int x, int y) {
  int src = graph[x][y], dest, max_dist = 0;
  bool visited[50][50] = {};
  queue<tuple<int, int, int>> q;

  visited[x][y] = true;
  q.push({x, y, 1});
  while (!q.empty()) {
    auto [x, y, dist] = q.front();

    q.pop();
    if (dist > max_dist) {
      max_dist = dist;
      dest = graph[x][y];
    }
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (is_inside(nx, ny) && !visited[nx][ny] && graph[nx][ny]) {
        visited[nx][ny] = true;
        q.push({nx, ny, dist + 1});
      }
    }
  }
  return {max_dist, src + dest};
}

int main() {
  pair<int, int> p = {0, 0};

  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%d", &graph[i][j]);
  for (int i = 0; i < N; i++) {
    if (graph[i][0]) p = max(p, bfs(i, 0));
    if (graph[i][M - 1]) p = max(p, bfs(i, M - 1));
  }
  for (int j = 0; j < M; j++) {
    if (graph[0][j]) p = max(p, bfs(0, j));
    if (graph[N - 1][j]) p = max(p, bfs(N - 1, j));
  }
  printf("%d", p.second);
}