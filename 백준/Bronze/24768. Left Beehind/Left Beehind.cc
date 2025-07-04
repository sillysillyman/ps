#include <cstdio>

int main() {
  int x, y;
  while (scanf("%d%d", &x, &y) && x || y)
    printf("%s.\n", x + y == 13 ? "Never speak again" : x > y ? "To the convention" : x < y ? "Left beehind" : "Undecided");
}