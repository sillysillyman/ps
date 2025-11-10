#include <cstdio>

int x, y;
char s[1001];

int main() {
  scanf("%*d%s", s);
  for (int i = 0; s[i]; i++) s[i] == 'E' ? ++x : s[i] == 'W' ? --x : s[i] == 'N' ? ++y : --y;
  printf("%d", (x < 0 ? -x : x) + (y < 0 ? -y : y));
}