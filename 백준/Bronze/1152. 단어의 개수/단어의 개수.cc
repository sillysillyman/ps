#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  string word;

  while (!(cin >> word).eof()) cnt++;
  cout << cnt;
}