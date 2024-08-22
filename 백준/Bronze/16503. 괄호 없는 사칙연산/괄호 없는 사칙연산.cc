#include <iostream>

using namespace std;

int calc(int x, int y, char op) {
  if (op == '+')
    return x + y;
  else if (op == '-')
    return x - y;
  else if (op == '*')
    return x * y;
  else if (op == '/')
    return x / y;
  return 0;
}

int main() {
  int K1, K2, K3;
  char O1, O2;

  cin >> K1 >> O1 >> K2 >> O2 >> K3;
  cout << min(calc(calc(K1, K2, O1), K3, O2), calc(K1, calc(K2, K3, O2), O1))
       << '\n'
       << max(calc(calc(K1, K2, O1), K3, O2), calc(K1, calc(K2, K3, O2), O1));
}