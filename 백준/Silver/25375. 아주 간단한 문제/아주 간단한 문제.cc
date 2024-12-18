#include <cstdio>

int main() {
  int Q;

  scanf("%d", &Q);
  while (Q--) {
    long long a, b;

    scanf("%lld%lld", &a, &b);
    printf("%d\n", 2 * a <= b && !(b % a));
  }
}