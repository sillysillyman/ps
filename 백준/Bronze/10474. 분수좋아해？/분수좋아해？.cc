#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int numerator, denominator;

    cin >> numerator >> denominator;
    if (numerator == 0 && denominator == 0) break;
    cout << numerator / denominator << ' ' << numerator % denominator << " / "
         << denominator << '\n';
  }
}