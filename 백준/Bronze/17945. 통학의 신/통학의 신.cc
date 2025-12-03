#include <cstdio>

int A, B, d;

int main() {
  scanf("%d%d", &A, &B);
  while (d * d < A * A - B) d++;
  printf(d ? "%d %d" : "%d", -A - d, -A + d);
}