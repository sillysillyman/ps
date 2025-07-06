#include <iostream>

using namespace std;

int arr[(int)1e6];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n = 0;
  while (cin >> k) arr[n++] = k;
  for (int i = 1; i < n; i++)
    if (arr[i - 1] > arr[i]) return cout << "Bad", 0;
  cout << "Good";
}