#include <cstdio>
#include <cstring>

int main() {
  int cnt = 0;
  char s[1'000];
  scanf("%s", s);
  for (int i = 0; s[i + 3]; i++)
    if (!strncmp(s + i, "DKSH", 4)) ++cnt;
  printf("%d", cnt);
}