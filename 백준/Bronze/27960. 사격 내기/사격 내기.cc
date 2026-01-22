#include <cstdio>

int A, B, C;
int a[10], b[10];

int main() {
  scanf("%d%d", &A, &B);
  for (int i = 9; i >= 0; i--) {
    if (A >= 1 << i) {
      A -= 1 << i;
      a[i] = 1;
    }
    if (B >= 1 << i) {
      B -= 1 << i;
      b[i] = 1;
    }
  }
  for (int i = 0; i < 10; i++)
    if (a[i] ^ b[i]) C += 1 << i;
  printf("%d", C);
}