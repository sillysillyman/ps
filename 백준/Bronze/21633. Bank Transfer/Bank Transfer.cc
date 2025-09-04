#include <cstdio>

int main() {
  int k;
  scanf("%d", &k);
  double c = 25 + k / 100.;
  printf("%.2lf", c < 100 ? 100 : c > 2000 ? 2000 : c);
}