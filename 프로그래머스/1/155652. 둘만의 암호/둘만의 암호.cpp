#include <algorithm>
#include <string>

using namespace std;

string solution(string s, string skip, int index) {
  string answer = "";

  for (char ch : s) {
    for (int i = 0; i < index; i++) {
      ch++;
      if (ch > 'z') ch = 'a';
      while (find(skip.begin(), skip.end(), ch) != skip.end()) {
        ch++;
        if (ch > 'z') ch = 'a';
      }
    }
    answer.push_back(ch);
  }
  return answer;
}