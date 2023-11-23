#include <cmath>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int P, Q;
map<ll, ll> A;

ll get_value(ll i) {
  if (A.find(i) != A.end()) return A[i];
  A[i] = get_value((ll)floor((double)i / P)) + get_value((ll)floor((double)i / Q));
  return A[i];
}

int main() {
  ll N;

  cin >> N >> P >> Q;
  A[0] = 1;
  cout << get_value(N);
}