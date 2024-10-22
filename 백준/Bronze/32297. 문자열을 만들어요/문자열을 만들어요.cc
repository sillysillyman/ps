#include <cstdio>
#include <cstring>

int main() {
  char str[11];

  scanf("%*d %s", str);
  printf("%s", strstr(str, "gori") != nullptr ? "YES" : "NO");
}