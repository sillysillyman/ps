#include <cstdio>

int main() {
  char a[21], b[21], c[21];
  while (scanf("%s", a) && a[0] != '#' && scanf("%s%s", b, c)) {
    printf("%s %s %s ", a, b, c);
    for (int i = 0; a[i]; i++) printf("%c", 'a' + (c[i] + b[i] - a[i] - 'a' + 26) % 26);
    printf("\n");
  }
}