#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, L, R;
  int arr[100000];
  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr + L - 1, arr + R);
  for (int i = 1; i < N; i++) if (arr[i - 1] > arr[i]) return cout << 0, 0;
  cout << 1;
}