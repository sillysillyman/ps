#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  vector<int> arr;

  cin >> N >> M;
  int size = N + M;
  while (size--) {
    int num;

    cin >> num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());
  for (int& num : arr) cout << num << ' ';
}