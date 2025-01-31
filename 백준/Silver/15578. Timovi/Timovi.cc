#include <iostream>

using namespace std;

int arr[200'000];

int main() {
  ios_base::sync_with_stdio(false);

  int N, K, M;
  cin >> N >> K >> M;

  while (M) {
    for (int i = 0; i < N; i++) {
      if (M >= K)
        arr[i] += K, M -= K;
      else
        arr[i] += M, M = 0;
    }
    for (int i = N - 2; i > 0; i--) {
      if (M >= K)
        arr[i] += K, M -= K;
      else
        arr[i] += M, M = 0;
    }
  }

  for (int i = 0; i < N; i++) cout << arr[i] << ' ';
}