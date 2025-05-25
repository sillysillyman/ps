#include <cstdio>
#include <cstring>

int main() {
  char s[21];
  scanf("%s", s);
  for (int len = strlen(s), i = 0; i < len / 2; i++)
    if (s[i] != s[len - i - 1]) return printf("false"), 0;
  printf("true");
}