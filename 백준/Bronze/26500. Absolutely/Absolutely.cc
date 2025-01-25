#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    double x, y;
    scanf("%lf %lf", &x, &y);
    printf("%.1lf\n", x >= y ? x - y : y - x);
  }
}