#include <cstdio>

char str[1'000'000];

int main() {
  scanf("%s", str);
  for (int i = 0;; i++) {
    if (char& ch = str[i]; ch == '\0')
      break;
    else if (ch == 'a')
      ch = '4';
    else if (ch == 'e')
      ch = '3';
    else if (ch == 'i')
      ch = '1';
    else if (ch == 'o')
      ch = '0';
    else if (ch == 's')
      ch = '5';
  }
  printf("%s", str);
}