#include <cstdio>

int main() {
  int x;
  char *s = "UOS";

  scanf("%d", &x);
  printf("%c", s[--x % 3]);
}