#include <algorithm>
#include <cstdio>
#include <cstring>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    char s[101], t[101];
    scanf("%s%s", s, t);
    printf("%s & %s are", s, t);
    std::sort(s, s + strlen(s));
    std::sort(t, t + strlen(t));
    printf("%sanagrams.\n", !strcmp(s, t) ? " " : " NOT ");
  }
}