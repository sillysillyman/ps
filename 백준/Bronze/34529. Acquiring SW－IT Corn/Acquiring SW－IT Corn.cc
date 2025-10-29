#include <cstdio>

int main() {
  int X, Y, Z, U, V, W;
  scanf("%d%d%d%d%d%d", &X, &Y, &Z, &U, &V, &W);
  printf("%d", U / 100 * X + V / 50 * Y + W / 20 * Z);
}