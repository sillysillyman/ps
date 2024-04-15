#include <algorithm>
#include <iostream>

using namespace std;

long long arr[200'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  long long left_sum = 0, right_sum = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  for (int i = 0; i < N / 2; i++) left_sum += arr[i];
  for (int i = N / 2; i < N; i++) right_sum += arr[i];
  cout << left_sum << ' ' << right_sum;
}