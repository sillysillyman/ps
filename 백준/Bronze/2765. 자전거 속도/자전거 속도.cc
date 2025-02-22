#include <cmath>
#include <cstdio>

int main() {
  int r, k = 1;
  double d, t;
  while (scanf("%lf%d%lf", &d, &r, &t) && r) {
    double m = M_PI * d * r / 63360;
    double v = 3600 * m / t;
    printf("Trip #%d: %.2lf %.2lf\n", k++, m, v);
  }
}