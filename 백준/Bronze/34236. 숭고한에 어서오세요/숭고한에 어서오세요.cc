#include <cstdio>

int main() {
  int N, a, b, c;
  scanf("%d%d%d", &N, &a, &b);
  if (N == 2) return printf("%d", 2 * b - a), 0;
  for (int i = 0; i < N - 3; i++) scanf("%*d");
  scanf("%d", &c);
  printf("%d", c + b - a);
}