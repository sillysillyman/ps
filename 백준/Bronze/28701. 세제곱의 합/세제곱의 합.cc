#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  int sum = N * (N + 1) / 2;
  printf("%d\n%d\n%d", sum, sum * sum, sum * sum);
}