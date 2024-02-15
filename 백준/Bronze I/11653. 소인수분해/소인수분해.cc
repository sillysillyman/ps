#include <iostream>

using namespace std;

int main() {
  int N;
  int divisor = 2;

  cin >> N;
  if (N == 1) return 0;
  while (N != 1) {
    if (N % divisor == 0) {
      cout << divisor << '\n';
      N /= divisor;
    } else
      divisor++;
  }
}