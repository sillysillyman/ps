#include <iostream>
#include <map>
#include <numeric>

using namespace std;

int arr[100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;
  while (t--) {
    int n;
    long long sum = 0;
    map<int, int> gcds;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) gcds[gcd(arr[i], arr[j])]++;
    }
    for (auto [k, v] : gcds) sum += (long long)k * v;
    cout << sum << '\n';
  }
}