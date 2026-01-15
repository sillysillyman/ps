#include <cstdio>

int main() {
  int H, v = 1;
  char s[30];
  scanf("%d%s", &H, s);
  for (int i = 0; s[i]; i++)
    if (s[i] == 'L' || s[i] == 'R') v = 2 * v + (s[i] == 'R');
  printf("%d", (1 << ++H) - v);
}