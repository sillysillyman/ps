#include <cstdio>

int main() {
  int Y, C, P;
  scanf("%d%d%d", &Y, &C, &P);
  C /= 2;
  printf("%d", (Y < C ? Y : C) < P ? (Y < C ? Y : C) : P);
}