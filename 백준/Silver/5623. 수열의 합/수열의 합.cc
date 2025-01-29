#include <cstdio>

int N;
long long total;
int mat[1'000][1'000];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf("%d", &mat[i][j]), total += mat[i][j];

  if (N == 2) return printf("%d %d", mat[0][1] / 2, mat[0][1] / 2), 0;
  total /= 2 * (N - 1);
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++) sum += mat[i][j];
    printf("%d ", (sum - total) / (N - 2));
  }
}