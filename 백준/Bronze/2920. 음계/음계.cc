#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int arr[8];

  for (int i = 0; i < 8; i++) cin >> arr[i];
  if (equal(arr, arr + 8, begin({1, 2, 3, 4, 5, 6, 7, 8}))) {
    cout << "ascending";
    return 0;
  }
  if (equal(arr, arr + 8, begin({8, 7, 6, 5, 4, 3, 2, 1}))) {
    cout << "descending";
    return 0;
  }
  cout << "mixed";
}