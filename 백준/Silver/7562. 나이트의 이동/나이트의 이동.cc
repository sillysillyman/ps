#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int board[300][300];
int visited[300][300];

bool is_inside(int x, int y, int l) {
  return 0 <= x && x < l && 0 <= y && y < l;
}

int main() {
  int T, l;
  pair<int, int> src, dst;

  cin >> T;
  while (T--) {
    queue<pair<int, int>> q;

    cin >> l;
    cin >> src.first >> src.second;
    cin >> dst.first >> dst.second;
    fill(&board[0][0], &board[l - 1][l], 0);
    fill(&visited[0][0], &visited[l - 1][l], 0);
    visited[src.first][src.second] = 1;
    q.push({src.first, src.second});
    while (!q.empty()) {
      auto [x, y] = q.front();

      q.pop();
      for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!is_inside(nx, ny, l) || visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        board[nx][ny] = board[x][y] + 1;
        q.push({nx, ny});
      }
    }
    // for (int i = 0; i < l; i++) {
    //   for (int j = 0; j < l; j++) {
    //     cout << board[i][j] << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';
    cout << board[dst.first][dst.second] << '\n';
  }
}