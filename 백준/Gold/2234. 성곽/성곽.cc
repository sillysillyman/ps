#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
map<int, int> m;
int visited[50][50];
int graph[50][50];

bool is_inside(int x, int y) { return 0 <= x && x < M && 0 <= y && y < N; }

int bfs(int src_x, int src_y, int mark) {
  int area = 1;
  queue<pair<int, int>> q;
  q.push({src_x, src_y});
  visited[src_x][src_y] = mark;

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (is_inside(nx, ny) && !visited[nx][ny] && !(graph[x][y] & (1 << i))) {
        q.push({nx, ny});
        ++area;
        visited[nx][ny] = mark;
      }
    }
  }

  return area;
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) scanf("%d", &graph[i][j]);

  int mark = 0;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      if (!visited[i][j]) m.insert({++mark, bfs(i, j, mark)});

  int max_area =
      max_element(m.begin(), m.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
      })->second;

  int max_combined_area = 0;
  for (int x = 0; x < M; x++) {
    for (int y = 0; y < N; y++) {
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (is_inside(nx, ny) && visited[x][y] != visited[nx][ny])
          max_combined_area =
              max(max_combined_area, m[visited[x][y]] + m[visited[nx][ny]]);
      }
    }
  }
  printf("%d\n%d\n%d", mark, max_area, max_combined_area);
}