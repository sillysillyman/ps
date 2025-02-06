#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

ll arr[100'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    ll b;
    cin >> b;
    arr[i] -= b;
  }

  ll m = arr[0];
  for (int i = 1; i < n; i++) m = gcd(m, arr[i]);
  cout << m;
}