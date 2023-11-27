#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    bool next_word = false;
    string word;
    string prev_word;

    cin >> word;
    prev_word = word;
    next_permutation(word.begin(), word.end());
    if (word < prev_word) cout << prev_word << '\n';
    else cout << word << '\n';
  }
}