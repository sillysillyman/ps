#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int row, col;
int max_dist = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int visited[50][50];
int map[50][50];

bool is_inside(int x, int y) { return 0 <= x && x < row && 0 <= y && y < col; }

void bfs(int x, int y) {
  queue<tuple<int, int, int>> q;

  q.push({x, y, 1});
  while (!q.empty()) {
    auto [x, y, dist] = q.front();

    max_dist = max(max_dist, dist);
    visited[x][y] = dist;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!visited[nx][ny] && map[nx][ny] && is_inside(nx, ny)) {
        visited[nx][ny] = dist + 1;
        q.push({nx, ny, dist + 1});
      }
    }
  }
}

int main() {
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      char land_or_water;

      cin >> land_or_water;
      if (land_or_water == 'W')
        map[i][j] = 0;
      else if (land_or_water == 'L')
        map[i][j] = 1;
    }
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (!map[i][j]) continue;
      fill(&visited[0][0], &visited[row - 1][col], 0);
      bfs(i, j);
    }
  }
  cout << max_dist - 1;
}