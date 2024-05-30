#include <algorithm>
#include <iostream>

using namespace std;

int digits[10];

int main() {
  int N;

  cin >> N;
  while (N) {
    int digit = N % 10;

    if (digit != 6 && digit != 9)
      ++digits[digit];
    else {
      if (digits[6] == digits[9])
        ++digits[digit];
      else
        ++digits[digits[6] < digits[9] ? 6 : 9];
    }
    N /= 10;
  }
  cout << *max_element(digits, digits + 10);
}