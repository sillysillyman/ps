#include <cstdio>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%s", (a & 1 && a < 4) && (!(b & 1) && b > 5) && (c == 2 || c == 5) ? "JAH" : "EI");
}