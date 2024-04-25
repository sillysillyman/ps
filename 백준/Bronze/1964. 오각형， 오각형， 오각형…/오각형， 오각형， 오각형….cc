#include <iostream>

using namespace std;

const int MOD = 45'678;

int main() {
  long long N;

  cin >> N;
  cout << (5 + (N - 1) + 3 * (N - 1) * (N + 2) / 2) % MOD;
}