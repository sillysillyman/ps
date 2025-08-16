#include <algorithm>
#include <iostream>

using namespace std;

int arr[(int)1e5];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  for (int i = 0; i < N; i++) arr[i] += N - i;
  sort(arr, arr + N);
  cout << arr[N - 1] + 1;
}