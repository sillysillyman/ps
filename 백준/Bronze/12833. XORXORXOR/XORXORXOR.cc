#include <cstdio>

int main() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  printf("%d", C & 1 ? A ^ B : A);
}