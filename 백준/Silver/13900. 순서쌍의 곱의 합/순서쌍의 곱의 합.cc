#include <iostream>

using namespace std;

long long arr[100'001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    arr[i] += arr[i - 1];
  }

  long long sum = 0;
  for (int i = 1; i <= N; i++) sum += (arr[i] - arr[i - 1]) * (arr[N] - arr[i]);
  cout << sum;
}