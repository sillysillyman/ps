#include <cstdio>

int main() {
  int b, N = 8;
  while (N--) {
    scanf("%d", &b);
    if (b == 9) return printf("F"), 0;
  }
  printf("S");
}