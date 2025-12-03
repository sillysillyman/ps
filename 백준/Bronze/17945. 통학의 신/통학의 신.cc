#include <cmath>
#include <cstdio>

int main() {
  int A, B, D;
  scanf("%d%d", &A, &B);
  D = A * A - B;
  if (D) printf("%d %d", -A - (int)sqrt(D), -A + (int)sqrt(D));
  else printf("%d", -A);
}