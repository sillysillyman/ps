#include <algorithm>
#include <cstdio>

int main() {
  int n, c;
  int T[1000] = {};
  scanf("%d%d", &n, &c);
  for (int t, i = 0; i < c; i++) {
    scanf("%d", &t);
    int *p = std::min_element(T, T + n);
    *p += t;
    printf("%ld ", p - T + 1);
  }
}