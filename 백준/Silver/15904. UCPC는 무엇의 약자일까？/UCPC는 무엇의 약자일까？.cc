#include <iostream>

using namespace std;

int main() {
  bool success[4];
  string str;

  getline(cin, str);
  fill(success, success + 4, false);
  for (auto c : str) {
    if (c == 'U' && !success[1] && !success[2] && !success[3]) success[0] = true;
    else if (success[0] && c == 'C' && !success[2] && !success[3]) success[1] = true;
    else if (success[0] && success[1] && c == 'P' && !success[3]) success[2] = true;
    else if (success[0] && success[1] && success[2] && c == 'C') success[3] = true;
  }
  if (success[0] && success[1] && success[2] && success[3])
    cout << "I love UCPC";
  else
    cout << "I hate UCPC";
}