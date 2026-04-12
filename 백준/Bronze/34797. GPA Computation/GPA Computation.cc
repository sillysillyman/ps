#include <cstdio>

int main() {
  char g;
  int n, c;
  double e = 0, s = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c%d", &g, &c);
    s += 69 - g;
    if (g < 68 && c < 3) e += .05 / c;
  }
  printf("%lf", s / n + e);
}