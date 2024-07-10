#include <cstdio>

int main() {
  for (int N, n, t = 1;; t++) {
    scanf("%d", &N);
    if (!N) break;
    while (N--) scanf("%d", &n);
    printf("Case %d: Sorting... done!\n", t);
  }
}