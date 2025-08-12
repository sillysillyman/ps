#include <cstdio>

int main() {
  char c;
  scanf("%*d\n");
  while (scanf("%c", &c) == 1 && c != '\n') c == ' ' ? printf("DORO ") : printf("%c", c);
  printf("DORO");
}