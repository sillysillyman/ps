#include <iostream>

using namespace std;

int arr[10000];

int main() {
  int N, M;
  int cnt = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (i == 0) continue;
    arr[i] += arr[i - 1];
  }

  int left = 0, right = 0;

  while (right < N) {
    if (arr[right] == M) {
      cnt++;
      right++;
      continue;
    }

    int diff = arr[right] - arr[left];

    if (diff == M) {
      cnt++;
      right++;
    } else if (diff > M)
      left++;
    else
      right++;
  }
  cout << cnt;
}