#include <cmath>
#include <cstdio>

int main() {
  int n;
  double c, s = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf", &c);
    s += c * c * c;
  }
  printf("%lf", cbrt(s));
}