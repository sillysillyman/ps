#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string name;

  while (getline(cin, name)) {
    int len = name.length();

    for (int i = 0; i < len; i++) {
      if (name[i] == 'e')
        name[i] = 'i';
      else if (name[i] == 'i')
        name[i] = 'e';
      else if (name[i] == 'E')
        name[i] = 'I';
      else if (name[i] == 'I')
        name[i] = 'E';
    }
    cout << name << '\n';
  }
}