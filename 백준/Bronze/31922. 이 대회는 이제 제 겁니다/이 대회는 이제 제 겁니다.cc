#include <cstdio>

int main() {
  int A, P, C;
  scanf("%d%d%d", &A, &P, &C);
  printf("%d", A + C > P ? A + C : P);
}