#include <iostream>

using namespace std;

int scores[101];
int arr[100'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ++scores[arr[i]];
  }
  for (int tmp, rank = 1, i = 100; i >= 0; i--) {
    tmp = scores[i];
    if (scores[i]) scores[i] = rank;
    rank += tmp;
  }
  for (int i = 0; i < n; i++) cout << scores[arr[i]] << '\n';
}