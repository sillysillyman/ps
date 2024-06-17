#include <iostream>
#include <map>
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
  int T;
  vector<string> orders;
  map<string, vector<string>> acronyms;

  cin >> T;
  while (T--) {
    int n;
    string acronym;

    cin >> acronym >> n;
    cin.ignore();
    orders.push_back(acronym);
    while (n--) {
      string str;

      getline(cin, str);
      vector<string> words = split(str, ' ');
      if (acronym.length() == words.size()) {
        bool is_valid = true;

        for (int i = 0; i < words.size(); i++) {
          if (acronym[i] != words[i][0]) {
            is_valid = false;
            break;
          }
        }
        if (is_valid) acronyms[acronym].push_back(str);
      }
    }
  }
  for (string& acronym : orders) {
    cout << acronym << '\n';
    for (string& str : acronyms[acronym]) cout << str << '\n';
  }
}