#include <iostream>
#include <map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int idx = 1;
  string name;

  while (cin >> n) {
    if (n == 0) break;

    map<int, pair<string, int>> students;

    cin.ignore();
    for (int i = 1; i <= n; i++) {
      getline(cin, name);
      students[i] = {name, 0};
    }

    int num;
    char letter;

    for (int i = 0; i < 2*n - 1; i++) {
      cin >> num >> letter;
      if (students[num].second == 1) students[num].second--;
      else students[num].second++;
    }
    for (auto p : students) {
      if (p.second.second == 1) {
        cout << idx << ' ' << p.second.first << '\n';
        break;
      }
    }
    idx++;
  }
}