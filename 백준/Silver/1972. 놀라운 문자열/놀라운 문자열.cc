#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    bool is_unique = true;
    string str;

    cin >> str;
    if (str == "*") break;
    for (int i = 1; i < str.length(); i++) {
      map<string, int> hash;

      for (int j = 0; j < str.length() - i; j++)
        hash[str.substr(j, 1) + str.substr(j + i, 1)]++;
      is_unique &= hash.size() == str.length() - i;
    }
    cout << str << " is ";
    if (!is_unique) cout << "NOT ";
    cout << "surprising.\n";
  }
}