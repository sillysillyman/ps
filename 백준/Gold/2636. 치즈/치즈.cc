#include <iostream>
#include <queue>

using namespace std;

int R, C;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[100][100];
pair<int, bool> graph[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  visited[x][y] = true;
  q.push({x, y});
  while (!q.empty()) {
    auto [x, y] = q.front();

    graph[x][y].second = true;
    q.pop();
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

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) cin >> graph[i][j].first;
  }

  int time = 0;
  int remained;

  while (true) {
    queue<pair<int, int>> borders;

    fill(&visited[0][0], &visited[R - 1][C], false);
    bfs(0, 0);
    for (int x = 0; x < R; x++) {
      for (int y = 0; y < C; y++) {
        if (!graph[x][y].first) continue;

        int cnt = 0;

        for (int i = 0; i < 4; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          if (graph[nx][ny].second) cnt++;
        }
        if (cnt) borders.push({x, y});
      }
    }
    if (borders.empty()) {
      cout << time << '\n' << remained;
      break;
    }
    remained = borders.size();
    while (!borders.empty()) {
      auto [x, y] = borders.front();

      graph[x][y].first = 0;
      borders.pop();
    }
    time++;
  }
}