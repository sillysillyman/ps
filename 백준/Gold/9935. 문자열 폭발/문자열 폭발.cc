#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str;
  string bomb;
  vector<char> s;

  str.reserve(1000000);
  cin >> str >> bomb;

  int len = bomb.length();

  for (char letter : str) {
    s.push_back(letter);
    if (s.size() >= len) {
      string buffer = "";

      for (int i = 1; i <= len; i++) buffer = s[s.size() - i] + buffer;
      if (buffer == bomb) {
        for (int i = 0; i < len; i++) s.pop_back();
      }
    }
  }
  if (s.empty())
    cout << "FRULA";
  else {
    for (char letter : s) cout << letter;
  }
}