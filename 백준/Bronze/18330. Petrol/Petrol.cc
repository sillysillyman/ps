#include <cstdio>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  k += 60;
  printf("%d", k >= n ? n * 1500 : 3000 * n - 1500 * k);
}