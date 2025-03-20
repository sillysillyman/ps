#include <cstdio>
#include <numeric>

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", std::gcd(x, y));
  }
}