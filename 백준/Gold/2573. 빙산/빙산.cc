#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N, M, cnt;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int visited[300][300];
int graph[300][300];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

bool melt() {
  vector<tuple<int, int, int>> icebergs;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (graph[i][j]) {
        int zeros = 0;

        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];

          if (is_inside(nx, ny) && !graph[nx][ny]) zeros++;
        }
        icebergs.push_back({i, j, zeros});
      }
    }
  }
  for (auto iceberg : icebergs) {
    auto [x, y, zeros] = iceberg;

    graph[x][y] -= zeros;
    if (graph[x][y] < 0) graph[x][y] = 0;
  }
  if (icebergs.empty())
    return false;
  else
    return true;
}

void bfs(int x, int y, int cnt) {
  queue<pair<int, int>> q;

  visited[x][y] = cnt;
  q.push({x, y});
  while (!q.empty()) {
    auto [x, y] = q.front();

    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && graph[nx][ny] && !visited[nx][ny]) {
        visited[nx][ny] = cnt;
        q.push({nx, ny});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cin >> graph[i][j];
  }

  bool separable = false;
  int year = 0;

  while (melt()) {
    cnt = 0;
    fill(&visited[0][0], &visited[N - 1][M], 0);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (!visited[i][j] && graph[i][j]) bfs(i, j, ++cnt);
      }
    }
    year++;
    if (cnt >= 2) {
      separable = true;
      break;
    }
  }
  if (separable)
    cout << year;
  else
    cout << 0;
}