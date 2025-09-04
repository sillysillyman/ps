#include <cstdio>

int main() {
  float k;
  scanf("%f", &k);
  k = 25 + k / 100;
  printf("%.2f", k < 100 ? 100 : k > 2000 ? 2000 : k);
}