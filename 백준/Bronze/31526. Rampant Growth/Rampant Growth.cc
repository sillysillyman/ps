#include <cstdio>

int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  long long v = r--;
  for (int i = 1; i < c; i++) {
    v *= r;
    v %= 998244353;
  }
  printf("%lld", v);
}