#include <algorithm>
#include <cstdio>

int main() {
  int n, c;
  int T[1000] = {};
  scanf("%d%d", &n, &c);
  for (int t, i = 0; i < c; i++) {
    scanf("%d", &t);
    int x = std::min_element(T, T + n) - T;
    T[x] += t;
    printf("%d ", x + 1);
  }
}