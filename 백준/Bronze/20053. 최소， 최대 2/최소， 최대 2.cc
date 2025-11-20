#include <cstdio>

int main() {
  int T, N, n, M, m;
  scanf("%d", &T);
  while (T--) {
    M = -1e6, m = 1e6;
    scanf("%d", &N);
    while (N--) {
      scanf("%d", &n);
      if (n > M) M = n;
      if (n < m) m = n;
    }
    printf("%d %d\n", m, M);
  }
}