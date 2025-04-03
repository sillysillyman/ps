#include <cstdio>
#include <cstring>

int cnt;
char s[1'001];

int main() {
  scanf("%s", s);
  for (int i = 0; s[i + 3]; i++)
    if (!strncmp(s + i, "DKSH", 4)) ++cnt;
  printf("%d", cnt);
}