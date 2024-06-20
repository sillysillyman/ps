#include <iostream>
#include <map>

using namespace std;

int main() {
  int N;
  int max_cnt = 0;
  map<string, int> cnts;

  cin >> N;
  while (N--) {
    string book;

    cin >> book;
    ++cnts[book];
    max_cnt = max(max_cnt, cnts[book]);
  }
  for (auto& [book, cnt] : cnts) {
    if (cnt == max_cnt) {
      cout << book;
      break;
    }
  }
}