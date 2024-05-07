#include <iostream>

using namespace std;

int main() {
  int num = 0;
  string word;

  cin >> word;
  for (char ch : word) {
    if ('A' <= ch && ch < 'a')
      num += ch - 'A' + 27;
    else if ('a' <= ch)
      num += ch - 'a' + 1;
  }
  for (int i = 2; i * i <= num; i++) {
    if (!(num % i)) {
      cout << "It is not a prime word.";
      return 0;
    }
  }
  cout << "It is a prime word.";
}