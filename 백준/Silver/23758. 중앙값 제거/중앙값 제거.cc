#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int arr[2000000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int cnt = 1;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);
  for (int i = 0; i < (N + 1) / 2; i++) cnt += (int)log2(arr[i]);
  cout << cnt;
}