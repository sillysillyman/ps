#include <cstdio>

int main() {
  int n;
  long long p, t;
  scanf("%d", &n);
  while (n--) {
    scanf("%lld%lld", &p, &t);
    printf("%lld\n", p - t / 7 + t / 4);
  }
}