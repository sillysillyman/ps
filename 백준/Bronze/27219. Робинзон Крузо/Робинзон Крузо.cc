#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n / 5; i++) putchar('V');
  for (int i = 0; i < n % 5; i++) putchar('I');
}