#include <cstdio>

int n;

int main() {
  for (int x, i = 0; i < 6; i++) {
    scanf("%d", &x);
    n += (i > 2 ? -1 : 1) * (i % 3 + 1) * x;
  }
  printf("%d", !n ? 0 : n > 0 ? 1 : 2);
}