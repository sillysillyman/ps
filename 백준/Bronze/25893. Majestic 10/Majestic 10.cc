#include <iostream>

using namespace std;

int main() {
  int n;
  int a, b, c;

  cin >> n;
  while (n--) {
    cin >> a >> b >> c;
    cout << a << ' ' << b << ' ' << c << '\n';
    if (a >= 10 && b >= 10 && c >= 10)
      cout << "triple-double\n\n";
    else if ((a >= 10 && b >= 10) || (b >= 10 && c >= 10) ||
             (c >= 10 && a >= 10))
      cout << "double-double\n\n";
    else if (a >= 10 || b >= 10 || c >= 10)
      cout << "double\n\n";
    else
      cout << "zilch\n\n";
  }
}