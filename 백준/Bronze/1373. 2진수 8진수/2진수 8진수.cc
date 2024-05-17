#include <iostream>

using namespace std;

int main() {
  string binary, octal;

  cin >> binary;
  while (binary.length() % 3) binary = '0' + binary;
  for (int i = 0; i < binary.length(); i += 3) {
    if (binary.substr(i, 3) == "000")
      octal += '0';
    else if (binary.substr(i, 3) == "001")
      octal += '1';
    else if (binary.substr(i, 3) == "010")
      octal += '2';
    else if (binary.substr(i, 3) == "011")
      octal += '3';
    else if (binary.substr(i, 3) == "100")
      octal += '4';
    else if (binary.substr(i, 3) == "101")
      octal += '5';
    else if (binary.substr(i, 3) == "110")
      octal += '6';
    else if (binary.substr(i, 3) == "111")
      octal += '7';
  }
  cout << octal;
}