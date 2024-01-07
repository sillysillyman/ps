#include <iostream>
#include <queue>

using namespace std;

int N;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int visited[200][200];
int board[200][200];

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

int bfs(int src_x, int src_y, int dest_x, int dest_y) {
  queue<pair<int, int>> q;

  visited[src_x][src_y] = 1;
  q.push({src_x, src_y});
  while (!q.empty()) {
    auto [x, y] = q.front();

    q.pop();
    if (x == dest_x && y == dest_y) return visited[x][y] - 1;
    for (int i = 0; i < 6; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny]) {
        visited[nx][ny] = visited[x][y] + 1;
        q.push({nx, ny});
      }
    }
  }
  return -1;
}

int main() {
  int r1, r2, c1, c2;

  cin >> N;
  cin >> r1 >> c1 >> r2 >> c2;
  cout << bfs(r1, c1, r2, c2);
}