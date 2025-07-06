#include <iostream>

using namespace std;

int arr[(int)1e6 + 1] = {(int)-1e6};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n = 1;
  while (cin >> k) {
    arr[n] = k;
    if (arr[n - 1] > arr[n++]) return cout << "Bad", 0;
  }
  cout << "Good";
}