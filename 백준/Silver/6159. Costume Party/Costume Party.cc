#include <algorithm>
#include <iostream>

using namespace std;

int N, S, cnt;
int arr[20'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  int left = 0, right = N - 1;
  while (left < right) {
    if (arr[left] + arr[right] <= S) {
      cnt += right - left;
      ++left;
    } else
      --right;
  }
  cout << cnt;
}