#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<pair<int, string>> v(7);
  for (auto &e : v) cin >> e.second >> e.first;
  sort(v.begin(), v.end());
  cout << v.back().second;
}