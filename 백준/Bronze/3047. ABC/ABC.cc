#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int arr[3];
  string order;

  cin >> arr[0] >> arr[1] >> arr[2] >> order;
  sort(arr, arr + 3);
  cout << arr[order[0] - 'A'] << ' ' << arr[order[1] - 'A'] << ' ' << arr[order[2] - 'A'];
}