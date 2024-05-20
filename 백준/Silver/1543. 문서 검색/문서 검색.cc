#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  string document, word;

  getline(cin, document);
  getline(cin, word);
  if (document.size() < word.size()) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i <= document.size() - word.size();) {
    if (document.substr(i, word.size()) != word)
      i++;
    else {
      ++cnt;
      i += word.size();
    }
  }
  cout << cnt;
}