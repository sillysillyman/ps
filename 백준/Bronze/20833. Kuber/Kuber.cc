#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  printf("%d", N * N * ++N * N / 4);
}