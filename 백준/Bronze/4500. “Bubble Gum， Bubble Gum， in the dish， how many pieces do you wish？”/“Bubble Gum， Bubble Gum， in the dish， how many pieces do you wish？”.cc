#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<string> words;

  while (getline(iss, buffer, delimiter)) words.push_back(buffer);
  return words;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;

  cin >> t;
  cin.ignore();
  while (t--) {
    int order;
    string line, start_name;
    vector<string> names;

    getline(cin, line);
    names = split(line, ' ');
    cin >> start_name >> order;
    cin.ignore();

    int start_pos;
    for (int i = 0; i < names.size(); i++) {
      if (names[i] == start_name) {
        start_pos = i;
        break;
      }
    }
    cout << names[(start_pos + order - 1) % names.size()] << '\n';
  }
}