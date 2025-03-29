#include <iostream>

using namespace std;

int arr[100'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }
  cin >> M;
  while (M--) {
    int i, j;
    cin >> i >> j;
    cout << arr[j] - arr[i - 1] << '\n';
  }
}