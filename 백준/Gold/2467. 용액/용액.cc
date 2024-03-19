#include <algorithm>
#include <iostream>

using namespace std;

int arr[100'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; ++i) cin >> arr[i];
  sort(arr, arr + N);

  int min_sum = 2e9;
  int left = 0, right = N - 1;
  pair<int, int> solutions;

  while (left < right) {
    int sum = arr[left] + arr[right];

    if (abs(sum) < min_sum) {
      min_sum = abs(sum);
      solutions = minmax(arr[left], arr[right]);
    }
    if (sum > 0)
      right--;
    else
      left++;
  }
  cout << solutions.first << ' ' << solutions.second;
}