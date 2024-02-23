#include <iostream>

using namespace std;
using ll = long long;

const int MAX = 100'000;
ll arr[MAX + 1];
pair<ll, ll> tree[4 * MAX + 1];

pair<ll, ll> init(int node, int start, int end) {
  if (start == end) return tree[node] = {arr[start], arr[start]};

  int mid = (start + end) / 2;
  pair<ll, ll> left = init(2 * node, start, mid);
  pair<ll, ll> right = init(2 * node + 1, mid + 1, end);

  return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
}

pair<ll, ll> query(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return {1'000'000'000, 0};
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;
  pair<ll, ll> left_subtree = query(2 * node, start, mid, left, right);
  pair<ll, ll> right_subtree = query(2 * node + 1, mid + 1, end, left, right);

  return {min(left_subtree.first, right_subtree.first), max(left_subtree.second, right_subtree.second)};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int a, b, i = 0; i < M; i++) {
    cin >> a >> b;
    
    auto [min_val, max_val] = query(1, 1, N, a, b);

    cout << min_val << ' ' << max_val << '\n';
  }
}