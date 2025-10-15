#include <cstdio>

int main() {
  int x, d;
  scanf("%d%d", &x, &d);
  printf(2 * x > d ? "take it" : "double it");
}