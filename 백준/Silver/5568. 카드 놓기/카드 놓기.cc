#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

string arr[10];
map<string, int> integers;

int main() {
  int n, k;

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  do {
    string num;

    for (int i = 0; i < k; i++) num += arr[i];
    integers[num]++;
  } while (next_permutation(arr, arr + n));
  cout << integers.size();
}