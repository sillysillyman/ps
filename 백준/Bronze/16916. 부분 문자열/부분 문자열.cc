#include <cstring>
#include <iostream>

using namespace std;

char S[1'000'001], P[1'000'001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> S >> P;
  cout << (strstr(S, P) != nullptr);
}