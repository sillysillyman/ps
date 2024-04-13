#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N, M;
  string line;

  cin >> N >> M;
  while (N--) {
    string line;

    cin >> line;
    reverse(line.begin(), line.end());
    cout << line << '\n';
  }
}