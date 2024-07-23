#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  ll sum = 0;

  cin >> N;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    sum += num;
  }
  cout << sum - (ll)N * (N - 1) / 2;
}