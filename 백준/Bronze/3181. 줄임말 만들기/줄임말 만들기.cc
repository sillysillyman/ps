#include <cstdio>
#include <cstring>

int main() {
  int F = 1, i;
  char s[101];
  const char *t[10] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
  while (~scanf("%s", s)) {
    for (i = 0; i < 10 && strcmp(s, t[i]); i++);
    if (F || i == 10) printf("%c", s[0] - 32);
    F = 0;
  }
}