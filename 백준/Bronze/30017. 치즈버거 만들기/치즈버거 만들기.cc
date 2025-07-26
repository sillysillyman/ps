#include <cstdio>

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  printf("%d", 2 * (--A < B ? A : B) + 1);
}