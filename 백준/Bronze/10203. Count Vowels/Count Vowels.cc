#include <cstdio>

int main() {
  int T;
  char s[30];
  scanf("%d", &T);
  while (T--) {
    int c = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++)
      c += s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
           s[i] == 'u';
    printf("The number of vowels in %s is %d.\n", s, c);
  }
}