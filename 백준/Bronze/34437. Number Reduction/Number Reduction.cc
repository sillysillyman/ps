#include <cstdio>

int main() {
  int N, n = 0;
  scanf("%d", &N);
  while (N != 1) {
    N % 2 ? N += 2 * N + 1 : N /= 2;
    ++n;
  }
  printf("%d", n);
}