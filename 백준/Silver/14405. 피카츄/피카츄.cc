#include <iostream>

using namespace std;

int main() {
  string S;

  cin >> S;
  for (int i = 0; i < S.length();) {
    if (S.substr(i, 2) == "pi" || S.substr(i, 2) == "ka")
      i += 2;
    else if (S.substr(i, 3) == "chu")
      i += 3;
    else {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}