#include <cstdio>
#include <cstring>

int M;
char s[22], t[22];

int main() {
  for (int x, i = 0; i < 7; i++) {
    scanf(" %s%d", t, &x);
    if (x > M) {
      M = x;
      strcpy(s, t);
    }
  }
  printf("%s", s);
}