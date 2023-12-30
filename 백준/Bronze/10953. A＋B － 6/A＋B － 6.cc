#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int A, B;
    char comma;

    cin >> A >> comma >> B;
    cout << A + B << '\n';
  }
}