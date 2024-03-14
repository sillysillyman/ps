#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int A, B;

  cin >> A >> B;
  cout << gcd(A, B) << '\n' << lcm(A, B);
}