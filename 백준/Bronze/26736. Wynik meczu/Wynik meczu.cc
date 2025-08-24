#include <iostream>

using namespace std;

int A, B;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  for (char &c : s) c == 'A' ? ++A : ++B;
  cout << A << " : " << B;
}