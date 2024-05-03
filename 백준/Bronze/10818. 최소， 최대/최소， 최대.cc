#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  int arr[1'000'000];

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  cout << *min_element(arr, arr + N) << ' ' << *max_element(arr, arr + N);
}