#include <iostream>

using namespace std;

int main() {
  int N = 0;
  long long S;

  cin >> S;
  for (int i = 1; i <= S; i++) {
    S -= i;
    N++;
    if (S <= i) break;
  }
  cout << N;
}