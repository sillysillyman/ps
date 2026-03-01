#include <iostream>
#include <map>

using namespace std;

int main() {
  string s;
  map<string, int> m;
  while (cin >> s) {
    m[s]++;
    if (m[s] > 1) return cout << "no", 0;
  }
  cout << "yes";
}