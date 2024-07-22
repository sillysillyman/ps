#include <iostream>

using namespace std;

bool is_vowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool is_valid_pwd(string pwd) {
  if (pwd.find_first_of("aeiou") == string::npos) return false;

  int len = pwd.length();

  for (int i = 0; i <= len - 2; i++) {
    if (pwd[i] == pwd[i + 1] && pwd.substr(i, 2) != "ee" &&
        pwd.substr(i, 2) != "oo")
      return false;
    if (i == len - 2) continue;
    if ((is_vowel(pwd[i]) && is_vowel(pwd[i + 1]) && is_vowel(pwd[i + 2])) ||
        (!is_vowel(pwd[i]) && !is_vowel(pwd[i + 1]) && !is_vowel(pwd[i + 2])))
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    string pwd;

    cin >> pwd;
    if (pwd == "end") break;
    cout << '<' << pwd << "> is ";
    if (!is_valid_pwd(pwd)) cout << "not ";
    cout << "acceptable.\n";
  }
}