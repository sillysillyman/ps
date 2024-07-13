#include <iostream>

using namespace std;

int main() {
  string expr;

  getline(cin, expr);
  cout << (expr[0] - '0' + expr[4] - '0' == expr[8] - '0' ? "YES" : "NO");
}