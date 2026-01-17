#include <cstdio>
#include <cmath>

int main() {
  int w, h, r;
  scanf("%d%d%d", &w, &h, &r);
  printf("%lf", w * h - M_PI_4 * r * r);
}