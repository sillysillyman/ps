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

  int N, M, K;
  int a, b;
  ll c;

  cin >> N >> M >> K;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  for (int i = 0; i < M + K; i++) {
    cin >> a >> b >> c;
    if (a == 1) {
      ll diff = c - arr[b];

      arr[b] = c;
      update(1, 1, N, b, diff);
    } else if (a == 2)
      cout << sum(1, 1, N, b, c) << '\n';
  }
}