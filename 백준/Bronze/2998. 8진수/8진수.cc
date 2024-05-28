#include <iostream>

using namespace std;

int main() {
  string binary, octal, padding;

  cin >> binary;
  padding = string((3 - binary.length() % 3) % 3, '0');
  binary = padding + binary;
  for (int i = 0; i < binary.length(); i += 3) {
    if (string triplet = binary.substr(i, 3); triplet == "000")
      octal += '0';
    else if (triplet == "001")
      octal += '1';
    else if (triplet == "010")
      octal += '2';
    else if (triplet == "011")
      octal += '3';
    else if (triplet == "100")
      octal += '4';
    else if (triplet == "101")
      octal += '5';
    else if (triplet == "110")
      octal += '6';
    else if (triplet == "111")
      octal += '7';
  }
  cout << octal;
}