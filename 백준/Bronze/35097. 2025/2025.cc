#include <cstdio>

int main() {
  int N;
  while (scanf("%d", &N) && N) printf("%d\n", N * N * (N + 1) * (N + 1) / 4);
}