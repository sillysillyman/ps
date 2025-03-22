#include <iostream>
#include <numeric>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  long long p = 1;
  while (n--) {
    long long i;
    cin >> i;
    p = lcm(p, i);
  }

  cout << p;
}