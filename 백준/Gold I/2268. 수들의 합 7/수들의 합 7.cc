#include <iostream>

using namespace std;
using ll = long long;

ll arr[1000001];
ll tree[4000001];

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

ll sum(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 0;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  return sum(2 * node, start, mid, left, right) +
         sum(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff) {
  if (idx < start || idx > end) return;
  tree[node] += diff;
  if (start != end) {
    int mid = (start + end) / 2;

    update(2 * node, start, mid, idx, diff);
    update(2 * node + 1, mid + 1, end, idx, diff);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  fill(arr + 1, arr + N + 1, 0);
  init(1, 1, N);
  while (M--) {
    int func;

    cin >> func;
    if (func == 0) {
      int i, j;

      cin >> i >> j;
      if (i > j) swap(i, j);
      cout << sum(1, 1, N, i, j) << '\n';
    } else if (func == 1) {
      int i, k;
      ll diff;

      cin >> i >> k;
      diff = k - arr[i];
      arr[i] = k;
      update(1, 1, N, i, diff);
    }
  }
}