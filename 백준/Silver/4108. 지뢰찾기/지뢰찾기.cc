#include <iostream>

using namespace std;

int R, C;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char board[100][100];

bool is_inside(int x, int y) { return 0 <= x && x < R && 0 <= y && y < C; };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    cin >> R >> C;
    if (R == 0 && C == 0) break;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> board[i][j];
        if (board[i][j] == '.') board[i][j] = '0';
      }
    }
    for (int x = 0; x < R; x++) {
      for (int y = 0; y < C; y++) {
        if (board[x][y] == '*') continue;
        for (int i = 0; i < 8; i++) {
          int nx = x + dx[i];
          int ny = y + dy[i];

          if (!is_inside(nx, ny)) continue;
          if (board[nx][ny] == '*') board[x][y] += 1;
        }
      }
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) cout << board[i][j];
      cout << '\n';
    }
  }
}