#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1'000'000;
int arr[MAX_N];
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < N; i++) {
    if (v.empty() || arr[i] > v.back()) {
      v.push_back(arr[i]);
      continue;
    }
    v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
  }
  cout << v.size();
}