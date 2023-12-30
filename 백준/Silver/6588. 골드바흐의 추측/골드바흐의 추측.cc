#include <iostream>
#include <map>

using namespace std;

int sieve[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 3; i < 1000001; i += 2) sieve[i] = 1;
  for (int i = 3; i < 1000001; i += 2) {
    if (sieve[i]) {
      for (int j = 3; i * j < 1000001; j += 2) sieve[i * j] = 0;
    }
  }

  int n;
  map<int, string> cache;

  while (true) {
    cin >> n;
    if (n == 0) break;
    // if (!cache[n].empty()) {
    //   cout << cache[n] << '\n';
    //   continue;
    // }

    // bool found = false;

    // for (int i = 3; i < n; i += 2) {
    //   if (!sieve[i]) continue;
    //   for (int j = n - 3; j >= 3; j -= 2) {
    //     if (sieve[j]) {
    //       if (i + j == n) {
    //         found = true;
    //         cache[n] =
    //             to_string(n) + " = " + to_string(i) + " + " + to_string(j);
    //         cout << cache[n] << '\n';
    //         break;
    //       } else if (i + j < n)
    //         break;
    //     }
    //   }
    //   if (found) break;
    // }
    for (int i = 3; i < n; i += 2) {
      if (sieve[i] && sieve[n - i]) {
        // cache[n] = to_string(n) + " = " + to_string(i) + " + " + to_string(n - i);
        // cout << cache[n] << '\n';
        cout << n << " = " << i << " + " << n - i << '\n';
        break;
      }
    }
  }
}