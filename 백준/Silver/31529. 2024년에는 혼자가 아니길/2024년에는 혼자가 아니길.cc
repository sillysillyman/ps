#include <cstdio>

int main() {
  int X, Y, W;

  scanf("%d%d", &X, &Y);
  W = (int)((2 * X - Y) / 4.0 * 2024);
  printf("%d", Y < X || W < 0 ? -1 : W);
}