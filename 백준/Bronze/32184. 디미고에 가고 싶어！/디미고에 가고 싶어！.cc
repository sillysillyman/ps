#include <cstdio>

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  printf("%d", (B - A + 1 + ((~A)&1) + (B&1)) / 2);
}