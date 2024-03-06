#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int map[1'000][1'000];
int visited[1'000][1'000][2];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; }

int bfs(pair<int, int> src, pair<int, int> dst) {
  queue<tuple<int, int, int>> q;

  q.push({src.first, src.second, 0});
  visited[src.first][src.second][0] = 1;
  while (!q.empty()) {
    auto [x, y, did_break_wall] = q.front();

    q.pop();
    if (x == dst.first && y == dst.second) return visited[x][y][did_break_wall];
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny)) {
        if (map[nx][ny] && !did_break_wall) {
          visited[nx][ny][1] = visited[x][y][did_break_wall] + 1;
          q.push({nx, ny, 1});
        } else if (!map[nx][ny] && !visited[nx][ny][did_break_wall]) {
          visited[nx][ny][did_break_wall] = visited[x][y][did_break_wall] + 1;
          q.push({nx, ny, did_break_wall});
        }
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    string row;

    cin >> row;
    for (int j = 0; j < M; j++) map[i][j] = row[j] - '0';
  }
  cout << bfs({0, 0}, {N - 1, M - 1});
}