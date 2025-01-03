#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  printf("%d", (N * N * N + 3 * N * N + 2 * N) / 2);
}