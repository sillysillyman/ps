#include <cstdio>

int main() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  printf("%d", A + B + C - (A < B && A < C ? A : B < C ? B : C));
}