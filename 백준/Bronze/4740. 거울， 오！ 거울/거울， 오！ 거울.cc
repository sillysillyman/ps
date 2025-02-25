#include <cstdio>
#include <cstring>

int main() {
  char s[81];
  while (scanf("%[^\n]", s) && strcmp(s, "***")) {
    getchar();
    for (int i = strlen(s) - 1; i >= 0; i--) printf("%c", s[i]);
    printf("\n");
  }
}