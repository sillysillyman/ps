#include <cstdio>
#include <cstring>

char s[120], t[120];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf(" %s%s", s, t);
    printf("%s\n", strcmp(s, t) ? "ERROR" : "OK");
  }
}