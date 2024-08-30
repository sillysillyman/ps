#include <cstdio>
#include <numeric>

using namespace std;

int main() {
  int n;

  scanf("%d", &n);
  while (n--) {
    long long a, b;

    scanf("%lld %lld", &a, &b);
    printf("%lld\n", lcm(a, b));
  }
}