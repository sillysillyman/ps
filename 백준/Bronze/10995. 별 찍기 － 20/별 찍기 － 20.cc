#include <iostream>

using namespace std;

int main() {
  int N;
  string line;

  cin >> N;
  for (int i = 0; i < N; i++) line += "* ";
  for (int i = 0; i < N; i++) {
    if (i & 1) cout << ' ';
    cout << line << '\n';
  }
}