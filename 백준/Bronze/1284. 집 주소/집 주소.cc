#include <iostream>

using namespace std;

int main() {
  string N;

  while (true) {
    cin >> N;
    if (N == "0") break;

    int width = N.length() + 1;

    for (char digit : N) {
      if (digit == '1')
        width += 2;
      else if (digit == '0')
        width += 4;
      else
        width += 3;
    }
    cout << width << '\n';
  }
}