#include <cstdio>

char s[501];

int main() {
  scanf("%*d %s", s);
  for (int i = 0; s[i]; i++) printf("%c", s[i] == 'I' ? 'i' : 'L');
}