#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int T;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    int A, B, C;

    cin >> A >> B >> C;
    cout << "Case #" << t << ": ";
    if (max({A, B, C}) >= A + B + C - max({A, B, C}))
      cout << "invalid!\n";
    else if (A == B && B == C)
      cout << "equilateral\n";
    else if (A == B || B == C || C == A)
      cout << "isosceles\n";
    else
      cout << "scalene\n";
  }
}