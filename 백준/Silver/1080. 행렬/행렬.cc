#include <cstdio>

int A[50][50];

int main() {
  int N, M, cnt = 0;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%1d", &A[i][j]);
  for (int i = 0; i < N; i++) {
    for (int x, j = 0; j < M; j++) {
      scanf("%1d", &x);
      if (x == A[i][j]) continue;
      if (i > N - 3 || j > M - 3) return printf("-1"), 0;
      ++cnt;
      for (int r = i; r < i + 3; r++)
        for (int c = j; c < j + 3; c++) A[r][c] ^= 1;
    }
  }
  printf("%d", cnt);
}