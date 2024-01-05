#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
  istringstream iss(str);
  string buffer;
  vector<string> splitted;

  while (getline(iss, buffer, delimiter)) splitted.push_back(buffer);
  return splitted;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  cin.ignore();
  while (T--) {
    string sentence;
    vector<string> words;

    getline(cin, sentence);
    words = split(sentence, ' ');
    for (auto& word : words) reverse(word.begin(), word.end());
    for (auto& word : words) cout << word << ' ';
    cout << '\n';
  }
}