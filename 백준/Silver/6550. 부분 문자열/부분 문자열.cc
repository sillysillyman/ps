#include <cstdio>

char s[100'001];

int main() {
  for (char *p; ~scanf("%s", p = s); puts(*p ? "No" : "Yes"))
    for (char c; (c = getchar()) ^ '\n'; p += *p == c)
      ;
}