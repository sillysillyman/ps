#include <cstdio>

int main() {
  int N;
  while (scanf("%d", &N) && N) printf("%d\n", N * (N + 1) * (2 * N + 1) / 6);
}