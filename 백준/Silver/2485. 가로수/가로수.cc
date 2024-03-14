#include <iostream>
#include <numeric>

using namespace std;

int arr[100'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, min_gap, cnt = 0;

  cin >> N;

  for (int i = 0; i < N; i++) cin >> arr[i];
  min_gap = arr[1] - arr[0];
  for (int i = 1; i < N - 1; i++) min_gap = gcd(min_gap, arr[i + 1] - arr[i]);
  for (int i = 0; i < N - 1; i++) {
    if (int gap = arr[i + 1] - arr[i]; gap == min_gap)
      continue;
    else
      cnt += gap / min_gap - 1;
  }
  cout << cnt;
}