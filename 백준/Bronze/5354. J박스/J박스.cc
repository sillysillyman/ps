#include <cstdio>

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
      printf("%c", (i < n || i >= n * (n - 1) || !(i % n) || !((i + 1) % n)) ? '#' : 'J');
      if (!((i + 1) % n)) printf("\n");
    }
    printf("\n");
  }
}