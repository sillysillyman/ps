#include <string>

using namespace std;

string solution(string s) {
  bool is_first = true;

  for (char& ch : s) {
    if (is_first) {
      if (!isdigit(ch) && ch != ' ') ch = toupper(ch);
      if (ch != ' ') is_first = false;
    } else if (ch == ' ')
      is_first = true;
    else if (!isdigit(ch))
      ch = tolower(ch);
  }
  return s;
}