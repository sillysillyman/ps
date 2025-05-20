#include <cstdio>

int main() {
  int N, cnt = 0;
  scanf("%d", &N);
  for (int n, i = 0; i <= N; i += 3) {
    n = i;
    while (n) {
      if (n % 10 == 3 || n % 10 == 6 || n % 10 == 9) ++cnt;
      n /= 10;
    }
  }
  printf("%d", cnt);
}