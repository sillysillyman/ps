#include <cstdio>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  printf("%d", k + 60 >= n ? n * 1500 : (k + 60) * 1500 + (n - k - 60) * 3000);
}