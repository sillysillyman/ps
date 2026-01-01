#include <cstdio>

int main() {
  int A, T, P;
  scanf("%d%d", &A, &T);
  P = 2 * (30 - A + T);
  printf("%d", P < 0 ? 0 : P);
}