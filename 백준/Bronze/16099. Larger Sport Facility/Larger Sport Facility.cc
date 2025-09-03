#include <cstdio>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    printf("%s\n", a * b > c * d ? "TelecomParisTech" : a * b < c * d ? "Eurecom" : "Tie");
  }
}