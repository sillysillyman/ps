#include <cstdio>

int main() {
  int N, a, b;
  scanf("%d", &N);
  N >= 1e6 ? (a = N / 5, b = N / 5 * 4) : N >= 5e5 ? (a = N / 20 * 3, b = N / 20 * 17) : N >= 1e5 ? (a = N / 10, b = N / 10 * 9) : (a = N / 20, b = N / 20 * 19);
  printf("%d %d", a, b);
}