#include <cstdio>

int i, sum;

int main() {
  char s[101];

  scanf("%[^\n]", s);
  for (; s[i] != '\0'; i++) sum += s[i];
  printf("%c", sum / i);
}