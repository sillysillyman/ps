#include <iostream>

using namespace std;

int main() {
  while (true) {
    int balance, money;
    char transaction;

    cin >> balance >> transaction >> money;
    if (balance == 0 && transaction == 'W' && money == 0) break;
    if (transaction == 'W')
      balance -= money;
    else if (transaction == 'D')
      balance += money;
    if (balance < -200)
      cout << "Not allowed\n";
    else
      cout << balance << '\n';
  }
}