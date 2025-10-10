#include <cstdio>

int main() {
  char s[4];
  scanf("%s", s);
  printf("%c%c%c%c", 'E'^'I'^s[0],'N'^'S'^s[1],'F'^'T'^s[2],'J'^'P'^s[3]);
}