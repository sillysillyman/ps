#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int L, C;
char letters[15];
string pwd;
vector<string> pwds;

bool is_valid(string pwd) {
  int vowel_cnt = 0;
  int consonant_cnt = 0;

  for (char letter : pwd) {
    if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
        letter == 'u')
      vowel_cnt++;
    else
      consonant_cnt++;
  }
  if (vowel_cnt > 0 && consonant_cnt > 1) return true;
  return false;
}

void back_tracking(int idx) {
  if (pwd.length() == L && is_valid(pwd)) pwds.push_back(pwd);
  for (int i = idx; i < C; i++) {
    pwd.push_back(letters[i]);
    back_tracking(i + 1);
    pwd.pop_back();
  }
}

int main() {
  cin >> L >> C;
  for (int i = 0; i < C; i++) cin >> letters[i];
  sort(letters, letters + C);
  back_tracking(0);
  for (string w : pwds) cout << w << '\n';
}