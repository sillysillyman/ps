#include <cstdio>

int board[5][5];

int count_bingo() {
  int cnt = 0;

  bool d1 = 1, d2 = 1;
  for (int i = 0; i < 5; i++) {
    d1 &= !board[i][i];
    d2 &= !board[i][4 - i];
  }
  cnt += d1 + d2;

  for (int i = 0; i < 5; i++) {
    bool row = 1, col = 1;
    for (int j = 0; j < 5; j++) {
      row &= !board[i][j];
      col &= !board[j][i];
    }
    cnt += row + col;
  }

  return cnt;
}

int main() {
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) scanf("%d", &board[i][j]);

  int T = 0;
  for (int x, t = 1; t <= 25; t++) {
    scanf("%d", &x);
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (board[i][j] == x) board[i][j] = 0;
    if (count_bingo() >= 3 && !T) T = t;
  }
  printf("%d", T);
}