#include <cstdio>
#include <cstring>

int main() {
  int T, c;
  char s[30];
  scanf("%d", &T);
  while (T--) {
    c = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) c += !!strchr("aeiou", s[i]);
    printf("The number of vowels in %s is %d.\n", s, c);
  }
}