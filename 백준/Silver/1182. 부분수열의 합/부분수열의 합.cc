#include <iostream>

using namespace std;

int arr[20];

int main() {
  int N, S;
  int cnt = 0;

  cin >> N >> S;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int sum, i = 1; i < 1 << N; i++) {
    sum = 0;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) sum += arr[j];
    }
    if (sum == S) cnt++;
  }
  cout << cnt;
}