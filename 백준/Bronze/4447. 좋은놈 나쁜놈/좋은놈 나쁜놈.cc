#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  cin.ignore();
  while (n--) {
    int good_cnt = 0, bad_cnt = 0;
    string name;

    getline(cin, name);
    for (char& ch : name) {
      if (ch == 'g' || ch == 'G')
        good_cnt++;
      else if (ch == 'b' || ch == 'B')
        bad_cnt++;
    }
    cout << name << " is ";
    if (good_cnt > bad_cnt)
      cout << "GOOD\n";
    else if (good_cnt == bad_cnt)
      cout << "NEUTRAL\n";
    else
      cout << "A BADDY\n";
  }
}