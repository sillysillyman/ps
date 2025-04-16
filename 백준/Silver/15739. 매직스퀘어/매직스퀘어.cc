#include <cstdio>

int d1, d2;
int arr[(int)1e4 + 1];
int row_sums[100];
int col_sums[100];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int x;
      scanf("%d", &x);
      ++arr[x];
      row_sums[i] += x;
      col_sums[j] += x;
      if (i == j) d1 += x;
      if (i + j == N - 1) d2 += x;
    }
  }

  for (int i = 1; i <= N * N; i++)
    if (arr[i] != 1) return printf("FALSE"), 0;

  int n = N * (N * N + 1) / 2;
  if (d1 != n || d2 != n) return printf("FALSE"), 0;
  for (int i = 0; i < N; i++)
    if (row_sums[i] != n || col_sums[i] != n) return printf("FALSE"), 0;

  printf("TRUE");
}