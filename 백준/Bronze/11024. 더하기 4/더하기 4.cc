#include <iostream>
#include <sstream>

using namespace std;

int main() {
  int T;

  cin >> T;
  cin.ignore();
  while (T--) {
    int num, sum = 0;
    string line;
    getline(cin, line);
    stringstream ss(line);

    while (ss >> num) sum += num;
    cout << sum << '\n';
  }
}