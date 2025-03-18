#include <cstdio>

char board[15][15];

int main() {
  int M, N, U, L, R, D;
  scanf("%d%d%d%d%d%d", &M, &N, &U, &L, &R, &D);
  for (int i = 0; i < M + U + D; i++)
    for (int j = 0; j < N + L + R; j++) board[i][j] = (i + j) & 1 ? '.' : '#';
  for (int i = U; i < M + U; i++)
    for (int j = L; j < N + L; j++) scanf(" %c", &board[i][j]);
  for (int i = 0; i < M + U + D; i++) {
    for (int j = 0; j < N + L + R; j++) printf("%c", board[i][j]);
    printf("\n");
  }
}