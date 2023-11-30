#include <iostream>

using namespace std;

int sum_digits(int n) {
  int sum = 0;

  while (n > 0) {
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;

  while (true) {
    cin >> N;
    if (N == 0) break;

    int sum;

    while ((sum = sum_digits(N))/10 > 0) N = sum;
    cout << sum << '\n';
  }
}