#include <cstdio>

int main() {
  int g, p, t;

  scanf("%d %d %d", &g, &p, &t);
  printf("%d", (g * p < g + p * t ? 1 : (g * p > g + p * t ? 2 : 0)));
}