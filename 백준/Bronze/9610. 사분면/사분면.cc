#include <iostream>

using namespace std;

int cnts[5];

int main() {
  int n;

  cin >> n;
  for (int x, y, i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > 0 && y > 0)
      cnts[0]++;
    else if (x < 0 && y > 0)
      cnts[1]++;
    else if (x < 0 && y < 0)
      cnts[2]++;
    else if (x > 0 && y < 0)
      cnts[3]++;
    else if (x == 0 || y == 0)
      cnts[4]++;
  }
  cout << "Q1: " << cnts[0] << '\n';
  cout << "Q2: " << cnts[1] << '\n';
  cout << "Q3: " << cnts[2] << '\n';
  cout << "Q4: " << cnts[3] << '\n';
  cout << "AXIS: " << cnts[4];
}