#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  int payment, change;

  cin >> payment;
  change = 1000 - payment;
  cnt += change / 500;
  change %= 500;
  cnt += change / 100;
  change %= 100;
  cnt += change / 50;
  change %= 50;
  cnt += change / 10;
  change %= 10;
  cnt += change / 5;
  change %= 5;
  cnt += change;
  cout << cnt;
}