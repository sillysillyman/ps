#include <algorithm>
#include <iostream>

using namespace std;

int arr[100000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int N, M;
  int cnt = 0;

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  int left = 0;
  int right = N - 1;

  while (left < right) {
    if (arr[left] + arr[right] >= M) {
      left++;
      right--;
      cnt++;
    } else
      left++;
  }
  cout << cnt;
}