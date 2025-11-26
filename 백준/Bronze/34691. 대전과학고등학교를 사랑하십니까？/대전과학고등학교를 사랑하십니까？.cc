#include <cstdio>

int main() {
  char s[7];
  while (scanf("%s", s) && *s != 'e')
    printf("%s\n", *s == 'f' ? "Forsythia koreana" : *s == 't' ? "Pinus densiflora" : "Panthera tigris");
}