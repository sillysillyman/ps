#include <algorithm>
#include <cstdio>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  printf("%d", 2 * std::min({a + c, b + 2 * c, 2 * a + b}));
}