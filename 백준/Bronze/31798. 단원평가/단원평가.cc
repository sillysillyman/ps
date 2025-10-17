#include <cstdio>

int main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  if (!a || !b)
    printf("%d", c * c - (!a ? b : a));
  else
    for (int i = 1;; i++)
      if (i * i == a + b) return printf("%d", i), 0;
}