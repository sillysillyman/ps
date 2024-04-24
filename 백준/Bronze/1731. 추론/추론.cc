#include <iostream>

using namespace std;

int arr[50];

int main() {
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  if (arr[0] * arr[2] == arr[1] * arr[1])
    cout << arr[N - 1] * (arr[1] / arr[0]);
  else if (arr[0] + arr[2] == 2 * arr[1])
    cout << arr[N - 1] + (arr[1] - arr[0]);
}