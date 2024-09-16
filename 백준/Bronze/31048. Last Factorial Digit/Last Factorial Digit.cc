#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int N;

    scanf("%d", &N);
    printf("%d\n", N == 1 ? 1 : N == 2 ? 2 : N == 3 ? 6 : N == 4 ? 4 : 0);
  }
}