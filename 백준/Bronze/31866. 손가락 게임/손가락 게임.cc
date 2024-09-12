#include <cstdio>

int main() {
  int a, b;

  scanf("%d%d", &a, &b);
  if (a == b || (a != 0 && a != 2 && a != 5 && b != 0 && b != 2 && b != 5))
    putchar('=');
  else if ((a == 0 && b == 2) || (a == 2 && b == 5) || (a == 5 && b == 0) ||
           ((a == 0 || a == 2 || a == 5) && (b != 0 && b != 2 && b != 5)))
    putchar('>');
  else
    putchar('<');
}