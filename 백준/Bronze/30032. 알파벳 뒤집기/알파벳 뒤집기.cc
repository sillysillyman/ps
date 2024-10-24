#include <cstdio>

char grid[10][10];

int main() {
  int N, D;

  scanf("%d%d", &N, &D);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf(" %c", &grid[i][j]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (D == 1)
        printf("%c", grid[i][j] == 'b'   ? 'p'
                     : grid[i][j] == 'd' ? 'q'
                     : grid[i][j] == 'p' ? 'b'
                                         : 'd');
      else
        printf("%c", grid[i][j] == 'b'   ? 'd'
                     : grid[i][j] == 'd' ? 'b'
                     : grid[i][j] == 'p' ? 'q'
                                         : 'p');
    }
    putchar('\n');
  }
}