#include <cstdio>

int main() {
  int n = 0;
  char s[8];
  scanf("%s", s);
  for (int i = 0; s[i]; i++) n += (!i || i == 6 ? 2 : 8 - i) * (s[i] - '0');
  n %= 11;
  printf("%c", !n ? 'J' : n == 10 ? 'Z' : 'A' + --n);
}