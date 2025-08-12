#include <cstdio>

int main() {
  char c;
  scanf("%*d\n");
  while (scanf("%c", &c) == 1 && c != '\n') {
    if (c == ' ') printf("DORO ");
    else printf("%c", c);
  }
  printf("DORO");
}