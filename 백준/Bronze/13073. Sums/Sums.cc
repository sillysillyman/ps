#include <cstdio>

int main() {
  int t;

  scanf("%d", &t);
  while (t--) {
    int N;

    scanf("%d", &N);
    printf("%d %d %d\n", N * (1 + N) / 2, N * N, N * (N + 1));
  }
}