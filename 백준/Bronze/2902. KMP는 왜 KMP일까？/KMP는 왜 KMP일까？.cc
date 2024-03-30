#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
  string buffer;
  istringstream iss(str);
  vector<string> res;

  while (getline(iss, buffer, delimiter)) res.push_back(buffer);
  return res;
}

int main() {
  string s;
  vector<string> v;
    
  cin >> s;
  v = split(s, '-');
  for (auto& s : v) cout << s[0];
}