#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int N;

    cin >> N;
    if (!N) break;

    int zeros = 0, ones = 0;

    while (N--) {
      int num;

      cin >> num;
      if (num)
        ++ones;
      else
        ++zeros;
    }
    cout << "Mary won " << zeros << " times and John won " << ones
         << " times\n";
  }
}