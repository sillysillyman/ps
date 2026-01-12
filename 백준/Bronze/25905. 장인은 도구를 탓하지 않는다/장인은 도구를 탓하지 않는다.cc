#include <cstdio>

int main() {
  double m = 1, p, P = 1e9 / 362880;
  for (int i = 0; i < 10; i++) {
    scanf("%lf", &p);
    P *= p;
    if (p < m) m = p;
  }
  P /= m;
  printf("%lf", P);
}