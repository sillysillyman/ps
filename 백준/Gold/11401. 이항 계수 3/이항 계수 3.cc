#include <iostream>

using ll = long long;
using namespace std;

const int MOD = 1000000007;
ll factorials[4000001];

ll pow_mod_p(ll num, int exp, int mod) {
  if (exp == 1) return num % mod;
  
  ll half = pow_mod_p(num, exp / 2, mod);

  if (!(exp % 2)) return ((half % mod) * (half % mod)) % mod;
  else return ((((num % mod) * (half % mod)) % mod) * (half % mod)) % mod;
}

ll binomial_coeff(ll n, int k, int mod) {
  ll top = factorials[n];
  ll bottom = (factorials[n - k] * factorials[k]) % mod;

  return (top * (pow_mod_p(bottom, mod - 2, mod) % mod)) % mod;
}

int main() {
  int N, K;

  cin >> N >> K;
  factorials[0] = 1;
  for (int i = 1; i <= N; i++) factorials[i] = ((i % MOD) * (factorials[i - 1] % MOD)) % MOD;
  cout << binomial_coeff(N, K, MOD);
}