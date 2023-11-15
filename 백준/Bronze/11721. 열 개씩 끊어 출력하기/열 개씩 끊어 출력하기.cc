#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  string word;

  cin >> word;

  for (char c : word) {
    cout << c;
    cnt++;
    if (cnt == 10) {
      cout << '\n';
      cnt = 0;
    }
  }
}