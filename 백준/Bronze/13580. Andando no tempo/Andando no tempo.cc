#include <cstdio>

int main() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  printf(A + B - C && A - B + C && -A + B + C && A - B && B - C && C - A ? "N" : "S");
}