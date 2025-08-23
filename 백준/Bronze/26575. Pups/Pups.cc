#include <cstdio>

int n;
double d, f, p;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%lf%lf%lf", &d, &f, &p);
    printf("$%.2lf\n", d * f * p);
  }
}