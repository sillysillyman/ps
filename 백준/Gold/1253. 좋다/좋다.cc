#include <algorithm>
#include <iostream>

using namespace std;

int arr[2000];

int main() {
  int N;
  int cnt = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  for (int i = 0; i < N; i++) {
    int left = 0;
    int right = N - 1;

    while (left < right) {
      if (left == i) {
        left++;
        continue;
      }
      if (right == i) {
        right--;
        continue;
      }
      if (arr[i] == arr[left] + arr[right]) {
        cnt++;
        break;
      }
      if (arr[i] > arr[left] + arr[right])
        left++;
      else if (arr[i] < arr[left] + arr[right])
        right--;
    }
  }
  cout << cnt;
}