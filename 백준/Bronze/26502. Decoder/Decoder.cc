#include <cstdio>

int main() {
  int n;
  char buffer[100];

  scanf("%d", &n);
  while (n--) {
    scanf(" %[^\n]", buffer);
    for (int i = 0; buffer[i]; i++) {
      char ch = buffer[i];
      printf("%c", ch == 'Y'   ? 'A'
                   : ch == 'A' ? 'E'
                   : ch == 'E' ? 'I'
                   : ch == 'I' ? 'O'
                   : ch == 'O' ? 'U'
                   : ch == 'U' ? 'Y'
                   : ch == 'y' ? 'a'
                   : ch == 'a' ? 'e'
                   : ch == 'e' ? 'i'
                   : ch == 'i' ? 'o'
                   : ch == 'o' ? 'u'
                   : ch == 'u' ? 'y'
                               : ch);
    }
    printf("\n");
  }
}