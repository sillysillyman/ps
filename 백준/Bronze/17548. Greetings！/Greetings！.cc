#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  string hey;

  cin >> hey;
  for (char& ch : hey) {
    if (ch == 'e') cnt++;
  }
  cout << 'h';
  for (int i = 0; i < 2 * cnt; i++) cout << 'e';
  cout << 'y';
}