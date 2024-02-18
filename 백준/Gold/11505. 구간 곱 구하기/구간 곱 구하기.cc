#include <iostream>

using namespace std;
using ll = long long;

const int MOD = 1000000007;
ll arr[1000001];
ll tree[4000001];

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             (init(2 * node, start, mid) * init(2 * node + 1, mid + 1, end)) %
             MOD;
}

ll multiply(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return 1;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  return (multiply(2 * node, start, mid, left, right) *
          multiply(2 * node + 1, mid + 1, end, left, right)) %
         MOD;
}

ll update(int node, int start, int end, int idx, ll new_val) {
  if (idx < start || idx > end) return tree[node];
  if (start == end) return tree[node] = new_val;

  int mid = (start + end) / 2;

  return tree[node] = (update(2 * node, start, mid, idx, new_val) *
                       update(2 * node + 1, mid + 1, end, idx, new_val)) %
                      MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, K;

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int i = 0; i < M + K; i++) {
    ll a, b, c;

    cin >> a >> b >> c;
    if (a == 1) {
      arr[b] = c;
      update(1, 1, N, b, c);
    } else if (a == 2) {
      if (b > c) swap(b, c);
      cout << multiply(1, 1, N, b, c) << '\n';
    }
  }
}