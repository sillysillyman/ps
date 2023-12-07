#include <iostream>

using namespace std;

int main() {
  long long mul = 0;
  string A, B;

  cin >> A >> B;
  for (char a : A) {
    for (char b : B) mul += (a - '0') * (b - '0');
  }
  cout << mul;
}