#include <algorithm>
#include <iostream>

using namespace std;

int arr[10'000];

int main() {
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  if (next_permutation(arr, arr + N)) {
    for (int i = 0; i < N; i++) cout << arr[i] << ' ';
  } else
    cout << -1;
}