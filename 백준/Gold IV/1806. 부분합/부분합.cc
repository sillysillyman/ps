#include <iostream>

using namespace std;

int arr[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, S;
  int min_len = 100000;

  cin >> N >> S;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    if (i == 1) continue;
    arr[i] += arr[i - 1];
  }

  bool success = false;
  int left = 0, right = 1;

  while (left < right && right <= N) {
    int diff = arr[right] - arr[left];

    if (diff >= S) {
      min_len = min(min_len, right - left);
      success = true;
      left++;
    } else
      right++;
  }
  if (success)
    cout << min_len;
  else
    cout << 0;
}