#include <cstdio>

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  printf("%d", A - 1 < B ? 2 * A - 1 : 2 * B + 1);
}