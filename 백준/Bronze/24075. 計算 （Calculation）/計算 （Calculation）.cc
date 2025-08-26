#include <cstdio>

int main() {
  int A, B;
  scanf("%d%d", &A, &B);
  B > 0 ? (A += B, B = A - 2 * B) : (A -= B, B = A + 2 * B);
  printf("%d\n%d", A, B);
}