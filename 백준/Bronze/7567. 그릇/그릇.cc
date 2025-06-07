#include <cstdio>

char s[51];

int main() {
  int n = 2;
  scanf("%s", s);
  for (int i = 1; s[i]; i++)
    n += (s[i] != s[i - 1]) + 1;
  printf("%d", 5 * n);
}