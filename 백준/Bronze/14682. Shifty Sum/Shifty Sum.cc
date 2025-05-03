#include <cstdio>

int main() {
  int N, k, s = 0;
  scanf("%d%d", &N, &k);
  for (int i = 0; i <= k; i++) {
    s += N;
    N *= 10;
  }
  printf("%d", s);
}