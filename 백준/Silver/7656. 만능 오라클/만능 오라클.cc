#include <iostream>
#include <regex>

using namespace std;

int main() {
  string s;
  getline(cin, s);

  regex pattern("What is([^.?]*)\\?");
  for (sregex_iterator it(s.begin(), s.end(), pattern), end; it != end; it++)
    cout << "Forty-two is" << it->str(1) << ".\n";
}