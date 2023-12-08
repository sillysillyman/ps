#include <iostream>
#include <map>

using namespace std;

int main() {
  string octopus_number;
  map<char, int> digits = {{'-', 0}, {'\\', 1}, {'(', 2}, {'@', 3}, {'?', 4},
                           {'>', 5}, {'&', 6},  {'%', 7}, {'/', -1}};

  while (true) {
    cin >> octopus_number;

    if (octopus_number == "#") break;

    int decimal = 0;
    int mul = 1;

    for (int i = octopus_number.length() - 1; i >= 0; i--) {
      decimal += digits[octopus_number[i]] * mul;
      mul *= 8;
    }
    cout << decimal << '\n';
  }
}