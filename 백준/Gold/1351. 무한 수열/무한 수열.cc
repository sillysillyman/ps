#include <cmath>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int P, Q;
map<ll, ll> A;

ll get_value(ll n) {
  if (A.find(n) != A.end()) return A[n];
  A[n] = get_value((ll)floor((double)n / P)) + get_value((ll)floor((double)n / Q));
  return A[n];
}

int main() {
  ll N;

  cin >> N >> P >> Q;
  A[0] = 1;
  cout << get_value(N);
}