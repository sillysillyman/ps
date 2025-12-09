#include <iostream>

using namespace std;

char p = 95, c;
int x, s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> c && c != '\0') {
    s += c > p ? ++x : x = 1;
    p = c;
  }
  cout << s;
}