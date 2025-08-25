#include <cstdio>

int A, B, C, max;

int main() {
  scanf("%d%d%d", &A, &B, &C);
  max = A <= C && B <= C ? C : A <= B && C <= B ? B : A;
  printf("%d", 3 * max - A - B - C);
}