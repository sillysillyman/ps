#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool graph[500][500];
int visited[500][500];

bool is_inside(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int bfs(int x, int y, int cnt) {
  int size = 0;
  queue<pair<int, int>> q;

  q.push({x, y});
  visited[x][y] = cnt;
  size++;
  while (!q.empty()) {
    auto [x, y] = q.front();

    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && graph[nx][ny] && !visited[nx][ny]) {
        visited[nx][ny] = cnt;
        q.push({nx, ny});
        size++;
      }
    }
  }
  return size;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> graph[i][j];
  }

  int cnt = 0;
  int max_size = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!graph[i][j] || visited[i][j]) continue;
      max_size = max(max_size, bfs(i, j, ++cnt));
    }
  }
  cout << cnt << '\n' << max_size;
}