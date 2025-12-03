#include <cstdio>

int main() {
  int A, B, d;
  scanf("%d%d", &A, &B);
  for (d = 0; d * d < A * A - B; d++) ;
  printf(d ? "%d %d" : "%d", -A - d, -A + d);
}