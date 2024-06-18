#include <iostream>

using namespace std;

int main() {
  bool is_increasing = true;
  bool is_decreasing = true;
  int N;
  string prev, curr;

  cin >> N;
  cin >> prev;
  for (int i = 0; i < N - 1; i++) {
    cin >> curr;
    if (prev < curr)
      is_decreasing = false;
    else if (prev > curr)
      is_increasing = false;
    prev = curr;
  }
  if (!is_increasing && !is_decreasing)
    cout << "NEITHER";
  else if (is_increasing)
    cout << "INCREASING";
  else if (is_decreasing)
    cout << "DECREASING";
}