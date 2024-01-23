#include <iostream>

using namespace std;

int main() {
  int refund = 0;

  for (int i = 0; i < 6; i++) {
    int bottles;

    cin >> bottles;
    refund += 5 * bottles;
  }
  cout << refund;
}