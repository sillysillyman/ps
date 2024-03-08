#include <iostream>

using namespace std;

int main() {
  int n;

  while (cin >> n) {
    int num = 1, len = 1;

    while (true) {
      if (num % n == 0) {
        cout << len << '\n';
        break;
      }
      num = (10 * num + 1) % n;
      len++;
    }
  }
}