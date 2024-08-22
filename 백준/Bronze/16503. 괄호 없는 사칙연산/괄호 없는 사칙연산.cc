#include <iostream>

using namespace std;

int calc(int x, int y, char op) {
  switch (op) {
    case '+':
      return x + y;
    case '-':
      return x - y;
    case '*':
      return x * y;
    case '/':
      return x / y;
  }
  return 0;
}

int main() {
  int K1, K2, K3;
  char O1, O2;

  cin >> K1 >> O1 >> K2 >> O2 >> K3;
  int ans2 = calc(calc(K1, K2, O1), K3, O2);
  int an2 = calc(K1, calc(K2, K3, O2), O1);

  cout << min(ans2, an2) << '\n' << max(ans2, an2);
}