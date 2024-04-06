#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    bool found_first_pair = false;
    int n;

    cin >> n;
    cout << "Pairs for " << n << ": ";
    for (int i = 1; i <= n / 2; i++) {
      for (int j = i + 1; j < n; j++) {
        if (i + j == n) {
          if (found_first_pair)
            cout << ", " << i << ' ' << j;
          else {
            found_first_pair = true;
            cout << i << ' ' << j;
          }
        }
      }
    }
    cout << '\n';
  }
}