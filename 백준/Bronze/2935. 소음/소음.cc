#include <iostream>

using namespace std;

string add_power_of_ten(string a, string b) {
  if (a.length() < b.length())
    swap(a, b);
  else if (a.length() == b.length()) {
    a[0] = '2';
    return a;
  }
  a[a.length() - b.length()] = '1';
  return a;
}

string multiply_power_of_ten(string a, string b) {
  for (int i = 0; i < b.length() - 1; i++) a += '0';
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  char op;
  string A, B;

  cin >> A >> op >> B;
  if (op == '+')
    cout << add_power_of_ten(A, B);
  else if (op == '*')
    cout << multiply_power_of_ten(A, B);
}