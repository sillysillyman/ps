#include <cstdio>

int main() {
  int N, W, s;
  scanf("%d%d", &N, &W);
  s = 10 * N + (N > 2) * 20 + (N == 5) * 50 - (W > 1e3) * 15;
  printf("%d", s > 0 ? s : 0);
}