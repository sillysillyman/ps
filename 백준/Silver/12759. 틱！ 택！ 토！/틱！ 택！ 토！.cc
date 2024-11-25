#include <cstdio>

int b[3][3];

bool does_win(int p) {
  return (b[0][0] == p && b[0][1] == p && b[0][2] == p) ||
         (b[1][0] == p && b[1][1] == p && b[1][2] == p) ||
         (b[2][0] == p && b[2][1] == p && b[2][2] == p) ||
         (b[0][0] == p && b[1][0] == p && b[2][0] == p) ||
         (b[0][1] == p && b[1][1] == p && b[2][1] == p) ||
         (b[0][2] == p && b[1][2] == p && b[2][2] == p) ||
         (b[0][0] == p && b[1][1] == p && b[2][2] == p) ||
         (b[0][2] == p && b[1][1] == p && b[2][0] == p);
}

int main() {
  bool has_winner = false;
  int p, x, y;

  scanf("%d", &p);
  while (~scanf("%d%d", &x, &y)) {
    b[--x][--y] = p;
    if (!has_winner && does_win(p)) {
      has_winner = true;
      printf("%d", p);
    }
    p = (2 * p) % 3;
  }
  if (!has_winner) printf("0");
}