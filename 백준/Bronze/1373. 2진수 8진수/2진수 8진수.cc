#include <iostream>

using namespace std;

int main() {
  string binary;
  string octal;

  cin >> binary;
  while (binary.length() % 3 != 0) binary = "0" + binary;
  for (int i = 0; i < binary.length(); i += 3) {
    if (stoi(binary.substr(i, 3)) == 0) octal += "0";
    else if (stoi(binary.substr(i, 3)) == 1) octal += "1";
    else if (stoi(binary.substr(i, 3)) == 10) octal += "2";
    else if (stoi(binary.substr(i, 3)) == 11) octal += "3";
    else if (stoi(binary.substr(i, 3)) == 100) octal += "4";
    else if (stoi(binary.substr(i, 3)) == 101) octal += "5";
    else if (stoi(binary.substr(i, 3)) == 110) octal += "6";
    else if (stoi(binary.substr(i, 3)) == 111) octal += "7";
  }
  cout << octal;
}