#include <iostream>

using namespace std;

int main() {
  int N;
  int bill1 = 0, bill2 = 0;

  cin >> N;
  while (N--) {
    int time;

    cin >> time;
    bill1 += 10 * (time / 30 + 1);
    bill2 += 15 * (time / 60 + 1);
  }
  bill1 == bill2
      ? (cout << "Y M " << bill1)
      : (bill1 < bill2 ? (cout << "Y " << bill1) : (cout << "M " << bill2));
}