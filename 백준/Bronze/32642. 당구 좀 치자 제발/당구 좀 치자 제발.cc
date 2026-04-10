#include <iostream>

using namespace std;

int N, n, c;
long long s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  while (N--) {
    cin >> n;
    c += n ? 1 : -1;
    s += c;
  }
  cout << s;
}