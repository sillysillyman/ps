#include <cstdio>

int main() {
  int N, n;
  scanf("%d", &N);
  n = ~-N / 9 + 1;
  printf("%d", n + (!(n & 1) * N & 1));
}