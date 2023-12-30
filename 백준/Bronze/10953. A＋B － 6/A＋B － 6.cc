#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  while (T--) {
    int A, B;
    char comma;

    cin >> A >> comma >> B;
    cout << A + B << '\n';
  }
}