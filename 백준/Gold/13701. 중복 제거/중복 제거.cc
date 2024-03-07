#include <bitset>
#include <iostream>

using namespace std;

bitset<33'554'432> bits;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int num;

  while (cin >> num) {
    if (bits[num]) continue;
    cout << num << ' ';
    bits[num] = 1;
  }
}