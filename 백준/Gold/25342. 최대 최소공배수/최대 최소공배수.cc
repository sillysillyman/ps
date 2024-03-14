#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    long long N;

    cin >> N;
    if (N % 2)
      cout << lcm(lcm(N, N - 1), N - 2) << '\n';
    else
      cout << max(lcm(lcm(N - 1, N - 2), N - 3), lcm(lcm(N, N - 1), N - 3))
           << '\n';
  }
}