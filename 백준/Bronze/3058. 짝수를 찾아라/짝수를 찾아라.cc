#include <iostream>

using namespace std;

int main() {
  int T;
  int num;

  cin >> T;
  while (T--) {
    int sum = 0;
    int min_num = 100;

    for (int i = 0; i < 7; i++) {
      cin >> num;
      if (num % 2 == 0) {
        sum += num;
        min_num = min(min_num, num);
      }
    }
    cout << sum << ' ' << min_num << '\n';
  }
}