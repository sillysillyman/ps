#include <cstdio>

int arr[(int)1e4 + 1];
int mat[100][100];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &mat[i][j]);
      ++arr[mat[i][j]];
    }
  }
  for (int i = 1; i <= N * N; i++)
    if (arr[i] != 1) return printf("FALSE"), 0;

  int x, y, n = N * (N * N + 1) / 2;
  for (int i = 0; i < N; i++) {
    x = 0;
    for (int j = 0; j < N; j++) x += mat[i][j];
    if (x != n) return printf("FALSE"), 0;
  }

  for (int j = 0; j < N; j++) {
    x = 0;
    for (int i = 0; i < N; i++) x += mat[i][j];
    if (x != n) return printf("FALSE"), 0;
  }

  x = 0, y = 0;
  for (int i = 0; i < N; i++) {
    x += mat[i][i];
    y += mat[N - 1 - i][i];
  }
  if (x != n || y != n) return printf("FALSE"), 0;

  printf("TRUE");
}