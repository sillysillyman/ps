#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  vector<string> suffixes;

  cin >> S;
  for (int i = 0; i < S.size(); i++) suffixes.push_back(S.substr(i));
  sort(suffixes.begin(), suffixes.end());
  for (auto& suffix : suffixes) cout << suffix << '\n';
}