#include <iostream>

using namespace std;

int main() {
  string hexadecimal;
  int decimal = 0, mul = 1;

  cin >> hexadecimal;
  for (int i = hexadecimal.length() - 1; i >= 0; i--) {
    if (isdigit(hexadecimal[i]))
      decimal += mul * (hexadecimal[i] - '0');
    else
      decimal += mul * (hexadecimal[i] - 'A' + 10);
    mul *= 16;
  }
  cout << decimal;
}