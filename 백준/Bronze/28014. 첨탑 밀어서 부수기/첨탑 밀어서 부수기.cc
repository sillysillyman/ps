#include <iostream>

using namespace std;

int N, p, c, n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> c;
    if (c >= p) n++;
    p = c;
  }
  cout << n;
}