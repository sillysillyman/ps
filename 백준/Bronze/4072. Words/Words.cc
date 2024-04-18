#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (true) {
    string word;

    cin >> word;
    if (word == "#") break;
    reverse(word.begin(), word.end());
    cout << word << ' ';
  }
}