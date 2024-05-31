#include <algorithm>
#include <iostream>

using namespace std;

string words[100];

bool is_palindrome(string word) {
  bool ret = true;
  int size = word.size();

  for (int i = 0; i < size / 2; i++) {
    if (word[i] != word[size - i - 1]) {
      ret = false;
      break;
    }
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  while (T--) {
    bool found = false;
    int k;

    cin >> k;
    for (int i = 0; i < k; i++) cin >> words[i];
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (i == j) continue;
        if (is_palindrome(words[i] + words[j])) {
          found = true;
          cout << words[i] + words[j] << '\n';
          break;
        }
      }
      if (found) break;
    }
    if (!found) cout << "0\n";
  }
}