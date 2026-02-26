#include <cstdio>
#include <cstring>

int main() {
  int F = 1, f;
  char s[101];
  const char *t[10] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};
  while (~scanf("%s", s)) {
    f = 0;
    for (int i = 0; i < 10; i++) if (!strcmp(s, t[i])) f = 1;
    if (!F && f) continue;
    printf("%c", s[0] - 32);
    F = 0;
  }
}