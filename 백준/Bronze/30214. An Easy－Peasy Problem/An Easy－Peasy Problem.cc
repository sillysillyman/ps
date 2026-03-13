#include <cstdio>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  putchar(2 * a >= b ? 'E' : 'H');
}