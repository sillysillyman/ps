#include <iostream>

using ll = long long;
using namespace std;

int sieve[10000001];

int main() {
  fill(sieve + 2, sieve + 10000001, 1);
  for (int i = 2; i < 10000001; i++) {
    if (sieve[i]) {
      for (int j = 2; (ll)i * j < 10000001; j++) sieve[i * j] = 0;
    }
  }

  int cnt = 0;
  ll A, B;

  cin >> A >> B;
  for (ll i = 2; i < 10000001; i++) {
    if (!sieve[i]) continue;
    if (i * i > B) break;

    ll almost_prime = i * i;

    while (almost_prime <= B) {
      if (A <= almost_prime) cnt++;
      almost_prime *= i;
      if (almost_prime % i != 0) break;
    }
  }
  cout << cnt << '\n';
}