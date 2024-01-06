#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  string word;

  cin >> N;
  while (N--) {
    cin >> word;
    sort(word.begin(), word.end());
    do {
      cout << word << '\n';
    } while (next_permutation(word.begin(), word.end()));
  }
}