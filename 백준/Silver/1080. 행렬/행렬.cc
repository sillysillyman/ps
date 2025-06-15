#include <cstdio>

int A[50][50];
int B[50][50];

int main() {
  int N, M, cnt = 0;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%1d", &A[i][j]);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) scanf("%1d", &B[i][j]);

  if (N < 3 || M < 3) {
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++)
        if (A[i][j] != B[i][j]) return printf("-1"), 0;
    return printf("0"), 0;
  }
  for (int i = 0; i < N - 2; i++) {
    for (int j = 0; j < M - 2; j++) {
      if (A[i][j] == B[i][j]) continue;
      ++cnt;
      for (int r = i; r < i + 3; r++)
        for (int c = j; c < j + 3; c++) A[r][c] ^= 1;
    }
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      if (A[i][j] != B[i][j]) return printf("-1"), 0;
  printf("%d", cnt);
}