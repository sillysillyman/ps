#include <algorithm>
#include <cstdio>

int main() {
  int N, c = 5;
  char s[101];
  scanf("%d%s", &N, s);
  for (int i = 0; i < N - 4; i++)
    c = std::min(c, (s[i] != 'e') + (s[i + 1] != 'a') + (s[i + 2] != 'g') + (s[i + 3] != 'l') + (s[i + 4] != 'e'));
  printf("%d", c);
}