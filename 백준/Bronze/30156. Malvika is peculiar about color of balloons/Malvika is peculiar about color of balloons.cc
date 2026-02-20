#include <cstdio>

int main() {
  int T, a, b;
  char s[101];
  scanf("%d", &T);
  while (T--) {
    a = 0, b = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) s[i] == 'a' ? a++ : b++;
    printf("%d\n", a < b ? a : b);
  }
}