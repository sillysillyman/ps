#include <cstdio>

int main() {
  int N;

  scanf("%d", &N);
  if (N == 1) {
    putchar('*');
    return 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N - 1; j++) putchar(' ');
    if (i != N - 1) putchar('*');
    if (!i) {
      putchar('\n');
      continue;
    }
    if (i == N - 1)
      for (int j = 0; j < 2 * N - 1; j++) putchar('*');
    else {
      for (int j = 0; j < 2 * i - 1; j++) putchar(' ');
      puts("*");
    }
  }
}