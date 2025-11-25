#include <algorithm>
#include <iostream>

using namespace std;

int n, k;
long long s;
int arr[(int)1e5];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, greater<>());
  for (int i = 0; i < k; i++) s += arr[i];
  cout << s;
}