#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

ll arr[1'000'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string num;

    cin >> num;
    reverse(num.begin(), num.end());
    arr[i] = stol(num);
  }
  sort(arr, arr + n);
  for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}