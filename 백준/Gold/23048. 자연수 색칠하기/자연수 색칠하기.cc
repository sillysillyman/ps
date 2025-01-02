#include <cstdio>

int sieve[500'001][2];

int main() {
  int N;
  scanf("%d", &N);

  int color = 1;
  sieve[1][1] = color;
  for (int i = 2; i <= N; i++) sieve[i][0] = 1;
  for (int i = 2; i <= N; i++) {
    if (!sieve[i][0]) continue;
    sieve[i][1] = ++color;
    for (int j = 2; i * j <= N; j++) {
      sieve[i * j][0] = 0;
      sieve[i * j][1] = sieve[i][1];
    }
  }
  printf("%d\n", color);
  for (int i = 1; i <= N; i++) printf("%d ", sieve[i][1]);
}