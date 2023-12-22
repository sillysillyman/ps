#include <iostream>
#include <map>

using namespace std;

int main() {
  string str;
  map<char, int> mobis;

  cin >> str;
  for (auto c : str) {
    if (c == 'M')
      mobis['M']++;
    else if (c == 'O')
      mobis['O']++;
    else if (c == 'B')
      mobis['B']++;
    else if (c == 'I')
      mobis['I']++;
    else if (c == 'S')
      mobis['S']++;
  }
  if (mobis['M'] >= 1 && mobis['O'] >= 1 && mobis['B'] >= 1 &&
      mobis['I'] >= 1 && mobis['S'] >= 1)
    cout << "YES";
  else
    cout << "NO";
}