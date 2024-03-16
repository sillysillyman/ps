#include <cmath>
#include <iostream>

using namespace std;

int main() {
  long long area;

  cin >> area;
  cout << fixed;
  cout.precision(6);
  cout << 4 * sqrt(area);
}