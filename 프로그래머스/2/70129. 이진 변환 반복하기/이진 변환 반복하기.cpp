#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string to_binary_str(int n) {
  string ret = "";

  while (n) {
    if (n % 2)
      ret = '1' + ret;
    else
      ret = '0' + ret;
    n /= 2;
  }
  return ret;
}

vector<int> solution(string s) {
  vector<int> answer(2);

  while (s != "1") {
    sort(s.begin(), s.end(), greater());
    while (s.back() == '0') {
      s.pop_back();
      answer[1]++;
    }
    s = to_binary_str(s.size());
    answer[0]++;
  }
  return answer;
}