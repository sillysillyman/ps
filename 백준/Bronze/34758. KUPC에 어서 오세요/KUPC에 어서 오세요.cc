#include <cstdio>

int N, X, Y, x, y;

int main() {
  scanf("%d%d%d", &X, &Y, &N);
  while (N--) {
    scanf("%d%d", &x, &y);
    printf("%d\n", x != X && y != Y);
  }
}