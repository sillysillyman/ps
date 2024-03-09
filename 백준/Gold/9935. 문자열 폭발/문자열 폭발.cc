#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string str, bomb, s;

  cin >> str >> bomb;

  int bomb_len = bomb.length();

  for (char letter : str) {
    s += letter;
    if (int len = s.length();
        len >= bomb_len && s.substr(len - bomb_len, bomb_len) == bomb)
      s.erase(s.end() - bomb_len, s.end());
  }
  if (s.empty())
    cout << "FRULA";
  else
    cout << s;
}