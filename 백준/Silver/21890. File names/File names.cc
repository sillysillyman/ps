#include <iostream>
#include <regex>

using namespace std;

int main() {
  int n, cnt = 0;

  cin >> n;

  regex pattern("^[a-z]{1,8}\\.[a-z]{1,3}$");

  while (n--) {
    string file;

    cin >> file;
    if (regex_match(file, pattern)) ++cnt;
  }
  cout << cnt;
}