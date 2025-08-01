#include <cstdio>

int T;
char s[21], t[21];

int main() {
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf(" %s%s", s, t);
    printf("Case %d: %s, %s\n", i, t, s);
  }
}