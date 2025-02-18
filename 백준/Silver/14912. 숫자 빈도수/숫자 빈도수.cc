#include <cstdio>

int main() {
  int n, d, cnt = 0;
  scanf("%d%d", &n, &d);

  for (int i = 1; i <= n; i++) {
    int num = i;
    while (num) {
      if (num % 10 == d) ++cnt;
      num /= 10;
    }
  }
  printf("%d", cnt);
}