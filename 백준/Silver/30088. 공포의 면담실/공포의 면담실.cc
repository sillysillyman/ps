#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, n, t, s;
  cin >> N;
  vector<int> v(N);
  while (N--) {
    s = 0;
    cin >> n;
    while (n--) cin >> t, s += t;
    v[N] = s;
  }
  sort(v.begin(), v.end());
  for (auto i = v.begin() + 1; i < v.end(); i++) *i += *(i - 1);
  cout << accumulate(v.begin(), v.end(), 0LL);
}