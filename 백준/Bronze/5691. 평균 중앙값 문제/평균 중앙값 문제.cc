#include <cstdio>

int main() {
  while (true) {
    int A, B;

    scanf("%d%d", &A, &B);
    if (A == 0 && B == 0) break;
    printf("%d\n", 2 * A - B);
  }
}