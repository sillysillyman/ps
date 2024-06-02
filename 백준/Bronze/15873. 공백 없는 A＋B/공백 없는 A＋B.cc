#include <iostream>

using namespace std;

int main() {
  string line;

  cin >> line;
  if (int len = line.length(); len == 2)
    cout << (line[0] - '0') + (line[1] - '0');
  else if (len == 3) {
    if (line[1] == '0')
      cout << 10 + (line[2] - '0');
    else if (line[2] == '0')
      cout << 10 + (line[0] - '0');
  } else if (len == 4)
    cout << 20;
}