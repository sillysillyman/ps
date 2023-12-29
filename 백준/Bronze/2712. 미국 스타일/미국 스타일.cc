#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  cout << fixed;
  cout.precision(4);
  while (T--) {
    double val;
    string unit;

    cin >> val >> unit;
    if (unit == "kg")cout << 2.2046 * val << " lb\n";
    else if (unit == "lb") cout << 0.4536 * val << " kg\n";
    else if (unit == "l") cout << 0.2642 * val << " g\n";
    else if (unit == "g") cout << 3.7854 * val << " l\n";
  }
}