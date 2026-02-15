#include <cstdio>

int main() {
  int T, F, S, P, C, N = 2;
  while (N--) {
    scanf("%d%d%d%d%d", &T, &F, &S, &P, &C);
    printf("%d ", 6 * T + 3 * F + 2 * S + P + 2 * C);
  }
}