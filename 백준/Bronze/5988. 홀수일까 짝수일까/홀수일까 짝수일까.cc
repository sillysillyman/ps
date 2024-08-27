#include <iostream>

using namespace std;

int main() {
  int N;

  cin >> N;
  while (N--) {
    string K;

    cin >> K;
    cout << ((K.back() - '0') & 1 ? "odd" : "even") << '\n';
  }
}