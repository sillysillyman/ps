#include <cstdio>
#include <numeric>

int main() {
  int n;
  scanf("%d", &n);

  long long p = 1;
  while (n--) {
    long long i;
    scanf("%lld", &i);
    p = std::lcm(p, i);
  }

  printf("%lld", p);
}