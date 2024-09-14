#include <cstdio>
#include <cstring>

int main() {
  char s[101];

  scanf("%[^\n]", s);

  int len = strlen(s), sum = 0;

  for (int i = 0; i < len; i++) sum += s[i];
  printf("%c", sum / len);
}