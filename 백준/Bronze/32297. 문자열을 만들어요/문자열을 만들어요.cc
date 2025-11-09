#include <cstdio>
#include <cstring>

int main() {
  char s[11];
  scanf("%*d%s", s);
  printf(strstr(s, "gori") ? "YES" : "NO");
}