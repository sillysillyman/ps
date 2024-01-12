#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int D = 0, P = 0;
  char winner;

  cin >> N;
  while (N--) {
    cin >> winner;
    if (abs(D - P) < 2 && winner == 'D') D++;
    else if (abs(D - P) < 2 && winner == 'P') P++;
  }
  cout << D << ':' << P;
}