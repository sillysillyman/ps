#include <cstdio>

int main() {
  int n;

  scanf("%d", &n);
  printf("%d", n <= 1 ? 1 : n == 2 ? 2 : n == 3 ? 6 : n == 4 ? 4 : 0);
}