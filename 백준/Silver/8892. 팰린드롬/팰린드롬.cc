#include <algorithm>
#include <iostream>

using namespace std;

string words[100];

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

        string palindrome = words[i] + words[j];
        reverse(palindrome.begin(), palindrome.end());

        if (words[i] + words[j] == palindrome) {
          found = true;
          cout << palindrome << '\n';
          break;
        }
      }
      if (found) break;
    }
    if (!found) cout << "0\n";
  }
}