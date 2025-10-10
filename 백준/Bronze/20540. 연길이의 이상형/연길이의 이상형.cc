#include <cstdio>

int main() {
  char s[4];
  scanf("%s", s);
  printf("%c%c%c%c", s[0] == 'E' ? 'I' : 'E', s[1] == 'N' ? 'S' : 'N', s[2] == 'F' ? 'T' : 'F', s[3] == 'J' ? 'P' : 'J');
}