#include <cstdio>

int n, cnt;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n / 3 + 1; i++) {
    for (int j = i; j < (n - 1) / 2 + 1; j++) {
      int k = n - i - j;
      if (k >= i && k >= j && k < i + j) ++cnt;
    }
  }
  printf("%d", cnt);
}