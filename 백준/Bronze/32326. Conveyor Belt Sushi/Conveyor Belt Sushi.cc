#include <cstdio>

int C;

int main() {
  for (int x, i = 3; i < 6; i++) {
    scanf("%d", &x);
    C += x * i;
  }
  printf("%d", C);
}