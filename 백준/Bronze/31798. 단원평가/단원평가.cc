#include <cmath>
#include <cstdio>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d", !a || !b ? c * c - (!a ? b : a) : (int)sqrt(a + b));
}