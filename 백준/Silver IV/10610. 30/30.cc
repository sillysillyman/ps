#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string N;

  cin >> N;
  sort(N.begin(), N.end(), greater<>());
  if (N.back() != '0') {
    cout << -1;
    return 0;
  }

  int digit_sum = 0;

  for (auto digit : N) {
    if (digit == '0') break;
    digit_sum += digit - '0';
  }
  if (digit_sum % 3 == 0)
    cout << N;
  else
    cout << -1;
}