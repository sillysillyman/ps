#include <cstdio>

int main() {
  int n = 0, N;
  scanf("%d", &N);
  for (int i = 0; i < 7; i++, N /= 10) n += (i > 5 ? 2 : 2 + i) * (N % 10);
  n %= 11;
  printf("%c", !n ? 'J' : n > 9 ? 'Z' : 'A' + --n);
}