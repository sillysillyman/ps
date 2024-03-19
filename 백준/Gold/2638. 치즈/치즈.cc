#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[100][100];
pair<bool, bool> graph[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  visited[x][y] = true;
  q.push({x, y});
  while (!q.empty()) {
    auto [x, y] = q.front();

    q.pop();
    graph[x][y].second = true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny] && !graph[nx][ny].first) {
        visited[nx][ny] = true;
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
    for (int j = 0; j < M; j++) cin >> graph[i][j].first;
  }

  int time = 0;

  while (true) {
    queue<pair<int, int>> borders;

    fill(&visited[0][0], &visited[N - 1][M], false);
    bfs(0, 0);
    for (int x = 0; x < N; x++) {
      for (int y = 0; y < M; y++) {
        int cnt = 0;

        if (!graph[x][y].first) continue;
        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          if (graph[nx][ny].second) cnt++;
        }
        if (cnt >= 2) borders.push({x, y});
      }
    }
    if (borders.empty()) {
      cout << time;
      break;
    }
    while (!borders.empty()) {
      auto [x, y] = borders.front();

      graph[x][y].first = false;
      borders.pop();
    }
    time++;
  }
}