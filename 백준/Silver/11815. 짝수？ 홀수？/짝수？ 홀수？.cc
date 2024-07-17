#include <cmath>
#include <cstdio>

using ll = long long;

int main() {
  int N;

  scanf("%d", &N);
  while (N--) {
    ll X;

    scanf("%lld", &X);
    printf("%d ", X == (ll)sqrt(X) * (ll)sqrt(X));
  }
}