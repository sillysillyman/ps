#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);
  while (N--) {
    char s[101];
    scanf(" %[^\n]", s);
    printf("god");
    int i = 0;
    while (s[i++] != ' ')
      ;
    for (; s[i]; i++)
      if (s[i] != ' ') printf("%c", s[i]);
    printf("\n");
  }
}