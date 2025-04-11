#include <cmath>
#include <cstdio>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d", abs(a / 4 + !!(a % 4) - b / 4 - !!(b % 4)) +
                   abs((a - 1) % 4 - (b - 1) % 4));
}