#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll A, B, C;

  cin >> A >> B;
  C = gcd(A, B);
  while (C--) cout << 1;
}