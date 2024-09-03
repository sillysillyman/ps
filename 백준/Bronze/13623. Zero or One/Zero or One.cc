#include <cstdio>

int main() {
  int A, B, C;

  scanf("%d%d%d", &A, &B, &C);
  printf("%c", A ? (B ? (C ? '*' : 'C') : (C ? 'B' : 'A'))
                 : (B ? (C ? 'A' : 'B') : (C ? 'C' : '*')));
}