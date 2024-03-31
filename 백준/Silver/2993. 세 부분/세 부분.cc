#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int len;
  string word;
  string a, b, c;
  vector<string> words;

  cin >> word;
  len = word.size();
  for (int i = 1; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      a = word.substr(0, i);
      b = word.substr(i, j - i);
      c = word.substr(j, len - j);
      reverse(a.begin(), a.end());
      reverse(b.begin(), b.end());
      reverse(c.begin(), c.end());
      words.push_back(a + b + c);
    }
  }
  sort(words.begin(), words.end());
  cout << words[0];
}