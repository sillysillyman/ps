#include <cstdio>

int main() {
  int n, k, a, b;
  scanf("%d%d%d%d", &n, &k, &a, &b);
  printf("%d %d", (n + k - 2) * b, (n - 1) * a);
}