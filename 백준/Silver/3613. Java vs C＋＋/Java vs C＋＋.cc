#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
  string buffer;
  istringstream iss(str);
  vector<string> words;

  while (getline(iss, buffer, delimiter)) words.push_back(buffer);
  return words;
}

int main() {
  string variable;

  cin >> variable;
  vector<string> words = split(variable + '_', '_');
  if (words.size() == 1) {
    if (isupper(variable[0])) {
      cout << "Error!";
      return 0;
    }
    for (char& ch : variable) {
      if (isupper(ch)) {
        cout << '_';
        ch -= ('A' - 'a');
      }
      cout << ch;
    }
  } else {
    for (int i = 0; i < words.size(); i++) {
      string& word = words[i];

      if (word.empty()) {
        cout << "Error!";
        return 0;
      }
      for (char& ch : word) {
        if (isupper(ch)) {
          cout << "Error!";
          return 0;
        }
      }
      if (i == 0) continue;
      word[0] += ('A' - 'a');
    }
    for (string& word : words) cout << word;
  }
}