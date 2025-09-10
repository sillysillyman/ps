#include <cstdio>

int main() {
  int N, K, n;
  scanf("%d%d", &N, &K);
  while (K--) {
    scanf("%d", &n);
    printf("%d ", n > (N + 1) / 2 ? N : 1);
  }
}