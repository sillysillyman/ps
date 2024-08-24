#include <iostream>

using namespace std;

int main() {
  int L, K = 1;
  string S;

  cin >> S;
  L = S.length();
  for (int i = 1; i < L; i++) {
    if (S[i - 1] >= S[i]) ++K;
  }
  cout << K;
}