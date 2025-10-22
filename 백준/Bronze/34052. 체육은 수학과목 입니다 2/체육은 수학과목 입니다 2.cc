#include <cstdio>

int main() {
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  printf(a + b + c + d <= 1500 ? "Yes" : "No");
}