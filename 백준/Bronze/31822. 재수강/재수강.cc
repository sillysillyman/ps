#include <cstdio>
#include <cstring>

int N, cnt;

int main() {
  char s[6], t[6];

  scanf("%5s%*s %d", s, &N);
  while (N--) {
    scanf(" %5s%*s", t);
    if (!strcmp(t, s)) ++cnt;
  }
  printf("%d", cnt);
}