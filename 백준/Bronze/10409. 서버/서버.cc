#include <iostream>

using namespace std;

int main() {
  int n, T, cnt = 0;

  cin >> n >> T;
  while (n--) {
    int t;

    cin >> t;
    if (T >= t) ++cnt;
    T -= t;
  }
  cout << cnt;
}