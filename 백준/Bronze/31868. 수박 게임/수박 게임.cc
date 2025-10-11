#include <cstdio>

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  printf("%d", K / (1 << --N));
}