#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int sum = 0;
  int dwarves[9];

  for (int i = 0; i < 9; i++) {
    cin >> dwarves[i];
    sum += dwarves[i];
  }

  bool found = false;

  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 9; j++) {
      if (dwarves[i] + dwarves[j] == sum - 100) {
        dwarves[i] = 100;
        dwarves[j] = 100;
        found = true;
        break;
      }
    }
    if (found) break;
  }
  // cout << '\n';
  sort(dwarves, dwarves + 9);
  // for (int i = 0; i < 7; i++) cout << dwarves[i] << "\n"[i == 6];
  for (int i = 0; i < 7; i++) cout << dwarves[i] << "\n";
}