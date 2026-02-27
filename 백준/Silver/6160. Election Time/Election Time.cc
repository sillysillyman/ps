#include <algorithm>
#include <iostream>

using namespace std;

struct Vote {
  int f, s, i;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  Vote arr[50000];
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i].f >> arr[i].s;
    arr[i].i = i + 1;
  }
  sort(arr, arr + N, [](auto &a, auto &b) { return a.f > b.f; });
  cout << max_element(arr, arr + K, [](auto &a, auto &b) { return a.s < b.s; })->i;
}