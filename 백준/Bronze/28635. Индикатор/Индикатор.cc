#include <cstdio>

int main() {
  int m, a, b;
  scanf("%d%d%d", &m, &a, &b);
  printf("%d", b - a + (b < a ? m : 0));
}