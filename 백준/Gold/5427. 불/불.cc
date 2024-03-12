#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int w, h, escape_time;
pair<int, int> start;
vector<pair<int, int>> fires;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int visited[1'000][1'000];
char graph[1'000][1'000];

bool is_inside(int x, int y) { return 0 <= x && x < h && 0 <= y & y < w; }

bool bfs() {
  queue<tuple<int, int, bool, int>> q;

  escape_time = 0;
  for (auto fire : fires) {
    visited[fire.first][fire.second] = -1;
    q.push({fire.first, fire.second, true, -1});
  }
  visited[start.first][start.second] = 1;
  q.push({start.first, start.second, false, 1});
  while (!q.empty()) {
    auto [x, y, is_fire, time] = q.front();

    q.pop();
    escape_time = max(escape_time, time);
    if (!is_fire && (x == 0 || x == h - 1 || y == 0 || y == w - 1)) return true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && graph[nx][ny] == '.' && !visited[nx][ny]) {
        if (is_fire) {
          visited[nx][ny] = -1;
          q.push({nx, ny, true, -1});
        } else {
          visited[nx][ny] = time + 1;
          q.push({nx, ny, false, time + 1});
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    cin >> w >> h;
    fill(&visited[0][0], &visited[h - 1][w], 0);
    fires.clear();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> graph[i][j];
        if (graph[i][j] == '@')
          start = {i, j};
        else if (graph[i][j] == '*')
          fires.push_back({i, j});
      }
    }
    if (bfs())
      cout << escape_time << '\n';
    else
      cout << "IMPOSSIBLE\n";
  }
}