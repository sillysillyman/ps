#include <cstdio>

int main() {
  int N, n = 1, t = 0;

  scanf("%d", &N);
  while (N) {
    if (N < n) n = 1;
    N -= n++;
    ++t;
  }
  printf("%d", t);
}