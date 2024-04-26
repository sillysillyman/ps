#include <string>

using namespace std;

bool solution(string s) {
  bool answer = true;

  if (!(s.length() == 4 || s.length() == 6)) return false;
  for (char& ch : s) answer &= isdigit(ch);
  return answer;
}