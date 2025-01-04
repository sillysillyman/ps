#include <cstdio>

int n, cnt;

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n / 3 + 1; i++) {
    for (int j = i; j < (n - i) / 2 + 1; j++) {
      int k = n - i - j;
      if (i + j > k) ++cnt;
    }
  }
  printf("%d", cnt);
}