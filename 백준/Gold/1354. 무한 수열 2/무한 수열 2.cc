#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

ll N, P, Q, X, Y;
map<ll, ll> A;

ll get_value(ll i) {
  if (i <= 0) return 1;
  if (A.find(i) != A.end()) return A[i];
  A[i] = get_value(i / P - X) + get_value(i / Q - Y);
  return A[i];
}

int main() {
  cin >> N >> P >> Q >> X >> Y;
  cout << get_value(N);
}