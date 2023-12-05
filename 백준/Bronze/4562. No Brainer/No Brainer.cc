#include <iostream>

using namespace std;

int main() {
  int n;
  int x, y;

  cin >> n;
  while (n--) {
    cin >> x >> y;
    x >= y ? cout << "MMM BRAINS\n" : cout << "NO BRAINS\n";
  }
}