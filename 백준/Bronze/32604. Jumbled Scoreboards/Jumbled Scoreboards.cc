#include <cstdio>

int n, A, B, a, b;

int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &a, &b);
    if (a < A || b < B) return printf("no"), 0;
    A = a, B = b;
  }
  printf("yes");
}