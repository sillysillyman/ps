#include <cstdio>

int main() {
  int T;
  char s[21];
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
      printf("%c", s[i]);
      if (s[i] == 'P' && s[i + 1] == 'O') printf("H");
    }
    printf("\n");
  }
}