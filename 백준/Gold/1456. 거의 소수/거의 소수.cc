#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int sieve[10000001];

int main() {
  fill (sieve + 2, sieve + 10000001, 1);
  for (int i = 2; i < 10000001; i++) {
    if (sieve[i]) {
      for (int j = 2; (ll)i * j < 10000001; j++) sieve[i * j] = 0;
    }
  }
//   cout << "sieve finished\n";

  ll A, B;
  ll cnt = 0;
//   vector<long long> almost_primes;

  cin >> A >> B;
//   cout << A << ' ' << B << '\n';
  for (ll i = 2; i < 10000001; i++) {
    if (!sieve[i]) continue;
    // cout << "start!\n";
    if (i * i > B) break;
    
    ll almost_prime = i * i;
    // cout << "prime: " << almost_prime << '\n';

    while (almost_prime <= B) {
      if (A <= almost_prime) {
        cnt++;
        // cout << "almost_prime: " << almost_prime << '\n';
      }
      
      almost_prime *= i;
      if (almost_prime % i != 0) {
        // cout << "break!!!\n";
        break;
      }
    }
    // cout << "cnt : " << cnt << '\n';
    // cout << '\n';
  }
  cout << cnt << '\n';
//   for (int i = 10000000; i >= 0; i--) {
//     if (sieve[i]) {
//         cout << i;
//         break;
//     }
//   }
}
//  70 262 606 976 455
// 100 000 000 000 000