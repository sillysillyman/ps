#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  string word;

  cin >> word;
  for (char letter : word) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
        letter == 'u')
      cnt++;
  }
  cout << cnt;
}