#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll A, B;

  cin >> A >> B;
  if (A > B) swap(A, B);
  cout << (A + B) * (B - A + 1) / 2;
}