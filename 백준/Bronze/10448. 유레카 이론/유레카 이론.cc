#include <iostream>

using namespace std;

int main() {
  int T, K;

  cin >> T;
  while (T--) {
    cin >> K;

    bool found = false;

    for (int i = 1; (i * (i + 1)) >> 1 < K; i++) {
      for (int j = 1; (j * (j + 1)) >> 1 < K; j++) {
        for (int k = 1; (k * (k + 1)) >> 1 < K; k++) {
          if (((i * (i + 1)) >> 1) + ((j * (j + 1)) >> 1) +
                  ((k * (k + 1)) >> 1) ==
              K) {
            cout << 1 << '\n';
            found = true;
            break;
          }
        }
        if (found) break;
      }
      if (found) break;
    }
    if (!found) cout << 0 << '\n';
  }
}