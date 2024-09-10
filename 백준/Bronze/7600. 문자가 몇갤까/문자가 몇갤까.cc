#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  while (getline(cin, line) && line != "#") {
    map<char, int> cnts;

    for (char& ch : line) {
      if (isalpha(ch)) ++cnts[tolower(ch)];
    }
    cout << cnts.size() << '\n';
  }
}