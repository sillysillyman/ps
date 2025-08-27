#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  for (int n = 1; n <= N; n++)
    cout << (!(n % 77)   ? "Wiwat!" : !(n % 11) ? "Super!" : !(n % 7)  ? "Hurra!" : to_string(n)) << '\n';
}