#include <cstdio>

int main() {
  int x;
  const char *uos = "UOS";

  scanf("%d", &x);
  printf("%c", uos[--x % 3]);
}