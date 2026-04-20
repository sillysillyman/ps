#include <cstdio>

int main() {
  int P, Q, A, B;
  scanf("%d%d%d%d", &P, &Q, &A, &B);
  printf("%d", P > Q ? A * Q : A * P + B * (Q - P));
}