#include <cstdio>

int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int A = a + 2 * b + 3 * c, B = d + 2 * e + 3 * f;
  printf("%d", A == B ? 0 : A > B ? 1 : 2);
}