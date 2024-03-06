#include <iostream>

using namespace std;

int main() {
  bool is_good[3];
  int n;

  cin >> n;
  for (int i = 0; i < 3; i++) {
    for (int digit, j = 0; j < n; j++) {
      cin >> digit;
      is_good[i] |= digit == 7;
    }
  }
  is_good[0] && is_good[1] && is_good[2] ? cout << "777" : cout << 0;
}