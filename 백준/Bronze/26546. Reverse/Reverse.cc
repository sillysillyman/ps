#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;
  while (n--) {
    int i, j;
    string word;

    cin >> word >> i >> j;
    for (int len = word.length(), k = 0; k < len; k++) {
      if (i <= k && k < j) continue;
      cout << word[k];
    }
    cout << '\n';
  }
}