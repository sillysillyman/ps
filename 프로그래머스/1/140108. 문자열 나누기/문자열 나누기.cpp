#include <string>

using namespace std;

int solution(string s) {
  int answer = 0;

  while (!s.empty()) {
    int x = 0, others = 0, idx;

    for (idx = 0; idx < s.size(); idx++) {
      if (s[idx] == s[0])
        x++;
      else
        others++;
      if (x == others) break;
    }
    if (idx == s.size())
      s.clear();
    else
      s.erase(s.begin(), s.begin() + idx + 1);
    answer++;
  }
  return answer;
}