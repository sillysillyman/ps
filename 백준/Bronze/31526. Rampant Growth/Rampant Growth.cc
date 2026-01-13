#include <cstdio>

int main() {
  int r, c;
  scanf("%d%d", &r, &c);
  long long v = r;
  for (int i = 0; i < c - 1; i++) {
    v *= r - 1;
    v %= 998244353;
  }
  printf("%lld", v);
}