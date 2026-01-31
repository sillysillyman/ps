#include <cstdio>
#include <cstring>

char s[101];

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    scanf("%s", s);
    if (strchr(s, 'S')) return printf("%s", s), 0;
  }
}