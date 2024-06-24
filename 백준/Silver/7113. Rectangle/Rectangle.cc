#include <algorithm>
#include <cstdio>

int main() {
  int n, m, cnt = 1;

  scanf("%d %d", &n, &m);
  while (n != m) {
    if (n < m) std::swap(n, m);
    n -= m;
    ++cnt;
  }
  printf("%d", cnt);
}