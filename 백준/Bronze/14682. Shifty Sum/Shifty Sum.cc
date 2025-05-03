#include <cstdio>

int main() {
  int N, k, sum = 0;
  scanf("%d%d", &N, &k);
  for (int i = 0; i <= k; i++) {
    sum += N;
    N *= 10;
  }
  printf("%d", sum);
}