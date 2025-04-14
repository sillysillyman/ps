#include <cstdio>

int main() {
  int N, n = 1e4;
  scanf("%d", &N);
  while (N--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (b / a < n) n = b / a;
  }
  printf("%d", n);
}