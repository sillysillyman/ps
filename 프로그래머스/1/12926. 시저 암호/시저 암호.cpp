#include <string>

using namespace std;

string solution(string s, int n) {
  for (char& ch : s) {
    if (!isalpha(ch)) continue;

    char base = islower(ch) ? 'a' : 'A';

    ch = base + (ch - base + n) % 26;
  }
  return s;
}