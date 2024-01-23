#include <iostream>

using namespace std;

const int MAX = 1000000;
int changes[100001];

int main() {
  int n;

  cin >> n;
  fill(changes + 1, changes + n + 1, MAX);
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) changes[i] = i / 2;
    if (i % 5 == 0) changes[i] = i / 5;
    if (i < 5) continue;
    if (changes[i - 5] != MAX) changes[i] = min(changes[i], changes[i - 5] + 1);
    if (changes[i - 2] != MAX) changes[i] = min(changes[i], changes[i - 2] + 1);
  }
  if (changes[n] == MAX) cout << -1;
  else cout << changes[n];
}