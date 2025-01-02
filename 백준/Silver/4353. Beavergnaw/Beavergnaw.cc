#include <cmath>
#include <cstdio>

int main() {
  int D, V;
  while (scanf("%d%d", &D, &V) && (D || V))
    printf("%.3lf\n", std::cbrt(D * D * D - 6 * V / M_PI));
}