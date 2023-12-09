#include <iostream>

using namespace std;

int main() {
  string phone_numbers;

  cin >> phone_numbers;
  if (phone_numbers.substr(0, 3) == "555") cout << "YES";
  else cout << "NO";
}