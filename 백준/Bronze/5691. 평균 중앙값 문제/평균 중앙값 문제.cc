#include <cstdio>

int main() {
  while (true) {
    int A, B;

    scanf("%d%d", &A, &B);
    if (!A && !B) break;
    printf("%d\n", 2 * A - B);
  }
}