#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T, N, k;
  int arr[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
  cin >> T;
  while (T--) {
    k = 13;
    cin >> N;
    k = lower_bound(arr, arr + 12, N) - arr + 1;
    if (k < 2) cout << "MIT time\n";
    else cout << "MIT^" << k << " time\n";
  }
}