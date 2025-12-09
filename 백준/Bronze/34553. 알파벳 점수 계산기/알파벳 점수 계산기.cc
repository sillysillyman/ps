#include <cstdio>

int main() {
  int x = 1, p = 1;
  char s[100001];
  scanf("%s", s);
  for (int i = 1; s[i]; i++)
    p += s[i] > s[i - 1] ? ++x : x = 1;
  printf("%d", p);
}