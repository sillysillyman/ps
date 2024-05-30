#include <algorithm>
#include <iostream>

using namespace std;

int digits[10];

int main() {
  string N;

  cin >> N;
  for (char& digit : N) {
    if (digit != '6' && digit != '9')
      ++digits[digit - '0'];
    else {
      if (digits[6] == digits[9])
        ++digits[digit - '0'];
      else
        ++digits[digits[6] < digits[9] ? 6 : 9];
    }
  }
  cout << *max_element(digits, digits + 10);
}