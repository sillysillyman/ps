#include <iostream>

using namespace std;
using ll = long long;

const int MAX_N = 100'000;
ll arr[MAX_N + 1];
pair<ll, int> tree[4 * MAX_N + 1];

pair<ll, int> init(int node, int start, int end) {
  if (start == end) return tree[node] = {arr[start], start};

  int mid = (start + end) / 2;

  return tree[node] =
             min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

pair<ll, int> find_min(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return {1'000'000'001, 100'001};
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;

  return min(find_min(2 * node, start, mid, left, right),
             find_min(2 * node + 1, mid + 1, end, left, right));
}

pair<ll, int> update(int node, int start, int end, int idx, int val) {
  if (idx < start || end < idx) return tree[node];
  if (start == end) return tree[node] = {val, idx};

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
    int query;

    cin >> query;
    if (query == 1) {
      int i;
      ll v;

      cin >> i >> v;
      arr[i] = v;
      update(1, 1, N, i, v);
    } else if (query == 2) {
      int i, j;

      cin >> i >> j;
      cout << find_min(1, 1, N, i, j).second << '\n';
    }
  }
}