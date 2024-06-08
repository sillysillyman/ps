#include <iostream>

using namespace std;

int main() {
  int A, B, C, D;

  cin >> A >> B >> C >> D;
  cout << stoll(to_string(A) + to_string(B)) +
              stoll(to_string(C) + to_string(D));
}