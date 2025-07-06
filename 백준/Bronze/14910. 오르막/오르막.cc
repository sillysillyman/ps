#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int prev = (int)-1e6, curr;
  while (cin >> curr) {
    if (prev > curr) return cout << "Bad", 0;
    prev = curr;
  }
  cout << "Good";
}