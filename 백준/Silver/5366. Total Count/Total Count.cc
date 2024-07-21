#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int total = 0, order = 0;
  vector<string> words;
  map<string, int> cnts;

  while (true) {
    string word;

    getline(cin, word);
    if (word == "0") break;

    ++cnts[word];
    if (cnts.size() > words.size()) words.push_back(word);
    ++total;
  }
  for (string& word : words) cout << word << ": " << cnts[word] << '\n';
  cout << "Grand Total: " << total;
}