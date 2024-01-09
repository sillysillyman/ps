#include <iostream>

using namespace std;

int main() {
  int change;

  cin >> change;
  change = 1000 - change;
  cout << change / 500 + (change % 500) / 100 + (change % 100) / 50 +
              (change % 50) / 10 + (change % 10) / 5 + (change % 5);
}