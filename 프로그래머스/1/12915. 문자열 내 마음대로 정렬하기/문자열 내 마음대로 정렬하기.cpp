#include <algorithm>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
  sort(strings.begin(), strings.end(), [&n](string s, string t) {
    if (s[n] == t[n]) return s < t;
    return s[n] < t[n];
  });
  return strings;
}