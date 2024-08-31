#include <iostream>
#include <map>

using namespace std;

int n, max_cnt;
map<string, int> cnts;

int main() {
  cin >> n;
  while (n--) {
    string name;

    cin >> name;
    ++cnts[name];
    max_cnt = max(max_cnt, cnts[name]);
  }
  for (auto& [k, v] : cnts) {
    if (v == max_cnt) cout << k << '\n';
  }
}