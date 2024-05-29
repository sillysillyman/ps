#include <iostream>

using namespace std;

int main() {
  int N, cnt = 0;
  string str;

  cin >> str >> N;
  while (N--) {
    int len = str.length();
    string ring;

    cin >> ring;
    for (int i = 0; i < 10; i++) {
      if (i <= 10 - len) {
        if (ring.substr(i, len) == str) {
          ++cnt;
          break;
        }
      } else {
        if (ring.substr(i) + ring.substr(0, len + i - 10) == str) {
          ++cnt;
          break;
        }
      }
    }
  }
  cout << cnt;
}