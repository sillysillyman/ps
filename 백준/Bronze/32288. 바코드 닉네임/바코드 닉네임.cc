#include <cstdio>

char s[501];

int main() {
  int n;
  scanf("%d %s", &n, s);
  for (int i = 0; i < n; i++) printf("%c", s[i] == 'I' ? 'i' : 'L');
}