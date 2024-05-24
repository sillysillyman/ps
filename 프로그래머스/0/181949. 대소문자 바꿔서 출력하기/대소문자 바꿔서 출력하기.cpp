#include <iostream>

using namespace std;

int main() {
  string str;

  cin >> str;
  for (char& ch : str) ch = isupper(ch) ? tolower(ch) : toupper(ch);
  cout << str;
}