#include <cstdio>

int main() {
  int N, A, B;
  scanf("%d%d%d", &N, &A, &B);
  printf("%d", N < A / 2 + B ? N : A / 2 + B);
}