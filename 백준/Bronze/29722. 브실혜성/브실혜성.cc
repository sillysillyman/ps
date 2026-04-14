#include <cstdio>

int main() {
  int y, m, d, N;
  scanf("%d-%d-%d%d", &y, &m, &d, &N);
  d += 360 * y + 30 * (m - 1) + N - 1;
  printf("%d-%02d-%02d", d / 360, d % 360 / 30 + 1, d % 30 + 1);
}