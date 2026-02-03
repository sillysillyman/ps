#include <cstdio>

int main() {
  int X;
  scanf("%*d%d", &X);
  printf("%lf", 1e4 / (100 - X) - 100);
}