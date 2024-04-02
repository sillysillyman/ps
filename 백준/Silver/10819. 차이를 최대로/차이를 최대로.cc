#include <algorithm>
#include <iostream>

using namespace std;

int arr[8];

int main() {
  int N, max_diff = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  do {
    int diff = 0;

    for (int i = 0; i < N - 1; i++) diff += abs(arr[i] - arr[i + 1]);
    max_diff = max(max_diff, diff);
  } while (next_permutation(arr, arr + N));
  cout << max_diff;
}