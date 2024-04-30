#include <map>
#include <vector>

using namespace std;

map<char, int> cache;

vector<int> solution(string s) {
  vector<int> answer(s.size());

  for (int i = 0; i < s.size(); i++) {
    if (cache.find(s[i]) != cache.end())
      answer[i] = i - cache[s[i]];
    else
      answer[i] = -1;
    cache[s[i]] = i;
  }
  return answer;
}