#include <iostream>

using namespace std;

int main() {
  string octal, binary;

  cin >> octal;
  for (char digit : octal) {
    if (digit == '0')
      binary += "000";
    else if (digit == '1')
      binary += "001";
    else if (digit == '2')
      binary += "010";
    else if (digit == '3')
      binary += "011";
    else if (digit == '4')
      binary += "100";
    else if (digit == '5')
      binary += "101";
    else if (digit == '6')
      binary += "110";
    else if (digit == '7')
      binary += "111";
  }
  while (binary[0] == '0' && binary.size() > 1) binary = binary.substr(1);
  cout << binary;
}