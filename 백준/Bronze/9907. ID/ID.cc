#include <cstdio>

int main() {
  int n = 0, N;
  scanf("%d", &N);
  for (int i = 0; N; i++, N /= 10) n += (2 + i * (i < 6)) * (N % 10);
  n %= 11;
  printf("%c", !n ? 'J' : n > 9 ? 'Z' : 'A' + --n);
}