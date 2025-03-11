#include <cstdio>

char grid[5][7][50];

int main() {
  int N;
  scanf("%d", &N);
  for (int k = 0; k < N; k++)
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 7; j++) scanf(" %1c", &grid[i][j][k]);

  int m, n, min_cnt = 36;
  for (int k = 0; k < N - 1; k++) {
    for (int l = k + 1; l < N; l++) {
      int cnt = 0;
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++) cnt += grid[i][j][k] != grid[i][j][l];
      if (cnt < min_cnt) {
        m = k;
        n = l;
        min_cnt = cnt;
      }
    }
  }

  printf("%d %d", ++m, ++n);
}