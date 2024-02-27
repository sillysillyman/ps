#include <iostream>

using namespace std;
using ll = long long;

const int MAX_N = 100'000;
ll arr[MAX_N + 1];
ll tree[4 * MAX_N + 1];

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

ll find_sum(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return 0;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;

  return find_sum(2 * node, start, mid, left, right) +
         find_sum(2 * node + 1, mid + 1, end, left, right);
}

ll update(int node, int start, int end, int idx, int val) {
  if (idx < start || end < idx) return tree[node];
  if (start == end) return tree[node] = val;

  int mid = (start + end) / 2;

  return tree[node] = update(2 * node, start, mid, idx, val) +
                      update(2 * node + 1, mid + 1, end, idx, val);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, Q;

  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  while (Q--) {
    int x, y, a;
    ll b;

    cin >> x >> y >> a >> b;
    if (x > y) swap(x, y);
    cout << find_sum(1, 1, N, x, y) << '\n';
    update(1, 1, N, a, b);
  }
}