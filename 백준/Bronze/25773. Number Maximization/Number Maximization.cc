#include <cstdio>

int digits[10];

int main() {
  int digit;

  while (~scanf("%1d", &digit)) ++digits[digit];
  for (int i = 9; i >= 0; i--)
    while (digits[i]--) printf("%d", i);
}