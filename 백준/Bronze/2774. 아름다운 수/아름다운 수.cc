#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;
  while (T--) {
    string X;

    cin >> X;
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    cout << X.length() << '\n';
  }
}