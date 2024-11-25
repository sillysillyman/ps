#include <cstdio>

int board[3][3];

bool does_win(int p) {
  return (board[0][0] == p && board[0][1] == p && board[0][2] == p) ||
         (board[1][0] == p && board[1][1] == p && board[1][2] == p) ||
         (board[2][0] == p && board[2][1] == p && board[2][2] == p) ||
         (board[0][0] == p && board[1][0] == p && board[2][0] == p) ||
         (board[0][1] == p && board[1][1] == p && board[2][1] == p) ||
         (board[0][2] == p && board[1][2] == p && board[2][2] == p) ||
         (board[0][0] == p && board[1][1] == p && board[2][2] == p) ||
         (board[0][2] == p && board[1][1] == p && board[2][0] == p);
}

int main() {
  bool has_winner = false;
  int p, x, y;

  scanf("%d", &p);
  while (~scanf("%d%d", &x, &y)) {
    board[--x][--y] = p;
    if (!has_winner && does_win(p)) {
      has_winner = true;
      printf("%d", p);
    }
    p = (2 * p) % 3;
  }
  if (!has_winner) printf("0");
}