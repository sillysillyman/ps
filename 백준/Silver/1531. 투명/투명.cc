#include <cstdio>

int matrix[101][101];

int main() {
  int N, M;

  scanf("%d %d", &N, &M);
  while (N--) {
    int x1, y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int x = x1; x <= x2; x++) {
      for (int y = y1; y <= y2; y++) ++matrix[x][y];
    }
  }

  int cnt = 0;

  for (int x = 1; x <= 100; x++) {
    for (int y = 1; y <= 100; y++) {
      if (matrix[x][y] > M) ++cnt;
    }
  }
  printf("%d", cnt);
}