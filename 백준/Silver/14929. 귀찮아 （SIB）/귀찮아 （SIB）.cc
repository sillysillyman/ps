#include <iostream>

using namespace std;

int arr[(int)1e5 + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long s = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  for (int i = 1; i < n; i++) s += (arr[i] - arr[i - 1]) * (arr[n] - arr[i]);
  cout << s;
}