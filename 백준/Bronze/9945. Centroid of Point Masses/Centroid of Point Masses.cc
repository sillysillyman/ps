#include <cstdio>

int main() {
  for (int t = 1;; t++) {
    int n;
    scanf("%d", &n);
    if (n < 0) break;

    long long X = 0, Y = 0, M = 0;
    for (int x, y, m, i = 0; i < n; i++) {
      scanf("%d%d%d", &x, &y, &m);
      X += x * m;
      Y += y * m;
      M += m;
    }

    printf("Case %d: %.2lf %.2lf\n", t, (double)X / M, (double)Y / M);
  }
}