#include <cstdio>

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int N, K, n = 0;

    scanf("%d%d", &N, &K);
    while (N--) {
      int x;

      scanf("%d", &x);
      n += x / K;
    }
    printf("%d\n", n);
  }
}