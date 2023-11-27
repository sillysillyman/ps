#include <iostream>

using namespace std;

int logic[26][26];

int main() {
  int n, m;
  string proposition;

  for (int i = 0; i < 26; i++) logic[i][i] = 1;
  cin >> n;
  cin.ignore();
  while (n--) {
    getline(cin, proposition);
    logic[proposition[0] - 'a'][proposition[5] - 'a'] = 1;
  }
  for (int k = 0; k < 26; k++) {
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (logic[i][j]) continue;
        if (logic[i][k] && logic[k][j]) logic[i][j] = 1;
      }
    }
  }
  cin >> m;
  cin.ignore();
  while (m--) {
    getline(cin, proposition);
    if (logic[proposition[0] - 'a'][proposition[5] - 'a'])
      cout << "T\n";
    else
      cout << "F\n";
  }
}