#include <cstdio>

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  for (int G, p, i = 0; i < K; i++) {
    scanf("%d", &G);
    p = G * 100 / N;
    printf("%d ", p < 5 ? 1 : p < 12 ? 2 : p < 24 ? 3 : p < 41 ? 4 : p < 61 ? 5 : p < 78 ? 6 : p < 90 ? 7 : p < 97 ? 8 : 9);
  }
}