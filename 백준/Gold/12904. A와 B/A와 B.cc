#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string S, T;

  cin >> S >> T;
  while (T.length() > 0) {
    if (T.back() == 'A') {
      T = T.substr(0, T.length() - 1);
      if (T == S) {
        cout << 1;
        return 0;
      }
    }
    else if (T.back() == 'B') {
      T = T.substr(0, T.length() - 1);
      reverse(T.begin(), T.end());
      if (T == S) {
        cout << 1;
        return 0;
      }
    }
  }
  cout << 0;
}