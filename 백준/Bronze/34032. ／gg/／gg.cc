#include <iostream>

using namespace std;

int N, n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> s;
  for (char &c : s) if (c == 'O') ++n;
  cout << (2 * n >= N ? "Yes" : "No");
}