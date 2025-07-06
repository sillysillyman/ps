#include <iostream>

using namespace std;

int arr[(int)1e6 + 1] = {(int)-1e6};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, flag = 0, n = 1;
  while (cin >> k) {
    arr[n] = k;
    if (arr[n - 1] > arr[n++]) flag = 1;
  }
  cout << (flag ? "Bad" : "Good");
}