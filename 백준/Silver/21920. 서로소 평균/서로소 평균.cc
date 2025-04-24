#include <iostream>
#include <numeric>

using namespace std;

int arr[(int)1e6];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, X;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  cin >> X;

  int size = 0;
  long long sum = 0;
  for (int i = 0; i < N; i++) {
    if (gcd(X, arr[i]) == 1) {
      ++size;
      sum += arr[i];
    }
  }

  cout << fixed;
  cout.precision(6);
  cout << sum * 1. / size;
}