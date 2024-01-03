#include <iostream>

using namespace std;

int main() {
  int N;
  double expectation = 0.0;

  cin >> N;
  for (int i = N; i >= 1; i--) {
    expectation += (double)N / i;
  }
  cout << expectation;
}