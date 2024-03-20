#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double area;

  cin >> area;
  cout << fixed;
  cout.precision(6);
  cout << 2 * M_PI * sqrt(area / M_PI);
}