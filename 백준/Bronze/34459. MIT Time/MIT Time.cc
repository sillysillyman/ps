#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T, N, k;
  int arr[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};
  cin >> T;
  while (T--) {
    k = 13;
    cin >> N;
    for (int i = 0; i < 12; i++) {
      if (N <= arr[i]) {
        k = i + 1;
        break;
      }
    }
    cout << "MIT";
    if (k - 1) cout << "^" << k;
    cout << " time\n";
  }
}