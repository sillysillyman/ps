#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    string word, next_word;

    cin >> word;
    next_word = word;
    next_permutation(next_word.begin(), next_word.end());
    cout << (word < next_word ? next_word : word) << '\n';
  }
}