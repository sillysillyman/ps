#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

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

  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string str;
    getline(cin, str);
    vector<string> tokens = split(str, ' ');

    for (auto& token : tokens)
      cout << (token.length() == 4 ? "****" : token) << ' ';
    cout << "\n\n";
  }
}