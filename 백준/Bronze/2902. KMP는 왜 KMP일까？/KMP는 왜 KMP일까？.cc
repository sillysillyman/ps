#include <iostream>

using namespace std;

int main() {
  int len;
  string str;

  cin >> str;
  len = str.length();
  cout << str[0];
  for (int i = 1; i < len; i++) {
    if (str[i - 1] == '-') cout << str[i];
  }
}