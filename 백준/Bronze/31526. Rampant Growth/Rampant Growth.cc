#include <cstdio>

int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  long long v = r--;
  while (--c) {
    v *= r;
    v %= 998244353;
  }
  printf("%lld", v);
}