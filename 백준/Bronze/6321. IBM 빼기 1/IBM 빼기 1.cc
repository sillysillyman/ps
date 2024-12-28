#include <cstdio>

int n;
char s[51];

int main() {
  scanf("%d", &n);
  for (int k = 1; k <= n; k++) {
    scanf("%s", s);
    printf("String #%d\n", k);
    for (int i = 0; s[i]; i++) printf("%c", 'A' + (s[i] + 1 - 'A') % 26);
    puts("\n");
  }
}