#include <cstdio>

using ll = long long;

int main() {
  int Q;
  scanf("%d", &Q);

  while (Q--) {
    ll l, r;
    scanf("%lld %lld", &l, &r);

    ll res = 45 * ((r - l + 1) / 9);
    for (ll i = r; i > r - (r - l + 1) % 9; i--) res += (i - 1) % 9 + 1;
    printf("%lld\n", res);
  }
}