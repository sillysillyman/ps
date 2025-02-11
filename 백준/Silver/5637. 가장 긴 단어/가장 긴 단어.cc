#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool is_word_char(char c) { return isalpha(c) || c == '-'; }

vector<string> split(string str, char delimiter) {
  string token;
  istringstream iss(str);
  vector<string> tokens;

  while (getline(iss, token, delimiter)) tokens.push_back(token);

  return tokens;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string str, line;
  while (getline(cin, line)) str += line + " ";
  vector<string> words = split(str, ' ');
  words.pop_back();
  string word = *max_element(
      words.begin(), words.end(), [](const string& a, const string& b) {
        return count_if(a.begin(), a.end(), is_word_char) <
               count_if(b.begin(), b.end(), is_word_char);
      });
  for (char& c : word)
    if (isalpha(c))
      cout << (char)tolower(c);
    else if (c == '-')
      cout << c;
}