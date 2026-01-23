
#include <cstdio>

int main() {
  int A, B, C, D, X;
  scanf("%d%d%d%d", &A, &B, &C, &D);
  for (int i = 0; i < 3; i++) {
    scanf("%d", &X);
    printf("%d\n", ((X - 1) % (A + B) < A) + ((X - 1) % (C + D) < C));
  }
}