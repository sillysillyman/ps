#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  cin.ignore();
  while (N--) {
    string line;

    getline(cin, line);
    line[0] = toupper(line[0]);
    cout << line << '\n';
  }
}