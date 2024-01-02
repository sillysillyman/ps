#include <iostream>

using namespace std;

int main() {
  int min_odd_number = ~(1 << 31);
  int num;
  int sum = 0;

  for (int i = 0; i < 7; i++) {
    cin >> num;
    if (num % 2) {
      sum += num;
      min_odd_number = min(min_odd_number, num);
    }
  }
  if (!sum)
    cout << -1;
  else
    cout << sum << '\n' << min_odd_number;
}