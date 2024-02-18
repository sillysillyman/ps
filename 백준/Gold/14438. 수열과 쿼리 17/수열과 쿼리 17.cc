#include <iostream>

using namespace std;
using ll = long long;

const int MAX = 1'000'000'000;
ll arr[100'001];
ll tree[400'001];

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

ll find_min(int node, int start, int end, int left, int right) {
  if (end < left || right < start) return MAX;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;

  return min(find_min(2 * node, start, mid, left, right),
             find_min(2 * node + 1, mid + 1, end, left, right));
}

ll update(int node, int start, int end, int idx, int val) {
  if (idx < start || end < idx) return tree[node];
  if (start == end) return tree[node] = val;

  int mid = (start + end) / 2;

  return tree[node] = min(update(2 * node, start, mid, idx, val),
                          update(2 * node + 1, mid + 1, end, idx, val));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  cin >> M;
  while (M--) {
    int query, i, j;
    ll v;

    cin >> query;
    if (query == 1) {
      cin >> i >> v;
      arr[i] = v;
      update(1, 1, N, i, v);
    } else if (query == 2) {
      cin >> i >> j;
      cout << find_min(1, 1, N, i, j) << '\n';
    }
  }
}