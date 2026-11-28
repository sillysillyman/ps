#include <cmath>
#include <cstdio>

int main() {
  long long a;
  scanf("%lld", &a);
  printf("%lf", 2 * a / sqrt(a / acos(-1)));
}