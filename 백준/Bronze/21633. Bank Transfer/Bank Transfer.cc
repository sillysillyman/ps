#include <cstdio>

int main() {
  int k;
  scanf("%d", &k);
  float c = 25 + k / 100.;
  printf("%.2f", c < 100 ? 100 : c > 2000 ? 2000 : c);
}