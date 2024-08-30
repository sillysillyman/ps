#include <cstdio>
#include <numeric>

int main() {
  int n;

  scanf("%d", &n);
  while (n--) {
    long long a, b;

    scanf("%lld %lld", &a, &b);
    printf("%lld\n", std::lcm(a, b));
  }
}