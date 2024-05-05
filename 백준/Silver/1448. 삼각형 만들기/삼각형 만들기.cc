#include <algorithm>
#include <iostream>

using namespace std;

int arr[1'000'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, sum = -1;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N, greater());
  for (int i = 0; i < N - 2; i++) {
    if (arr[i] < arr[i + 1] + arr[i + 2]) {
      sum = arr[i] + arr[i + 1] + arr[i + 2];
      break;
    }
  }
  cout << sum;
}