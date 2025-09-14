#include <cstdio>

int main() {
  int l, r;
  scanf("%d%d", &l, &r);
  if (!l && !r) return printf("Not a moose"), 0;
  printf("%s %d", l - r ? "Odd" : "Even", l > r ? 2 * l : 2 * r);
}