#include <cstdio>

int main() {
  int N;
  scanf("%d", &N);

  while (N--) {
    int A, B, X;
    scanf("%d%d%d", &A, &B, &X);
    printf("%d\n", A * (X - 1) + B);
  }
}