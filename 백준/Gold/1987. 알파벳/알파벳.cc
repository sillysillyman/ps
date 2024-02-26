#include <iostream>

using namespace std;

int R, C;
int max_depth = 1;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool checked[26];
bool visited[20][20];
char board[20][20];

bool is_inside(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; }

void dfs(int x, int y, int depth) {
  if (checked[board[x][y] - 'A']) {
    max_depth = max(max_depth, depth - 1);
    return;
  }
  checked[board[x][y] - 'A'] = true;
  visited[x][y] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (is_inside(nx, ny) && !visited[nx][ny]) dfs(nx, ny, depth + 1);
  }
  max_depth = max(max_depth, depth);
  checked[board[x][y] - 'A'] = false;
  visited[x][y] = false;
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    string row;

    cin >> row;
    for (int j = 0; j < C; j++) board[i][j] = row[j];
  }
  fill(checked, checked + 26, false);
  fill(&visited[0][0], &visited[R - 1][C], false);
  dfs(0, 0, 1);
  cout << max_depth;
}