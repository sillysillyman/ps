#include <cstdio>

int main() {
  int u, d, p, U, D, P, H;
  scanf("%d%d%d%d%d%d%d", &u, &U, &d, &D, &p, &P, &H);
  for (int t = 0; t < 5001; t++) {
    if (!(t % u)) H -= U;
    if (!(t % d)) H -= D;
    if (!(t % p)) H -= P;
    if (H < 1) return printf("%d", t), 0;
  }
}