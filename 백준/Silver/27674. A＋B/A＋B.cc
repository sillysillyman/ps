#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int t;

  cin >> t;
  while (t--) {
    string num;

    cin >> num;
    sort(num.begin(), num.end(), greater());
    cout << stoll(num.substr(0, num.length() - 1)) + num.back() - '0' << '\n';
  }
}