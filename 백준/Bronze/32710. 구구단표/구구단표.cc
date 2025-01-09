#include <cstdio>

int N, flag;

int main() {
  scanf("%d", &N);
  flag = N == 1;
  for (int i = 2; i < 10; i++) flag |= !(N % i) && (N <= 9 * i);
  printf("%d", flag);
}