#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll tree[4'000'001];

ll sum(int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 0;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;
  return sum(2 * node, start, mid, left, right) +
         sum(2 * node + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll val) {
  if (idx < start || end < idx) return;

  if (start == end) {
    tree[node] += val;
    return;
  }

  int mid = (start + end) / 2;
  update(2 * node, start, mid, idx, val);
  update(2 * node + 1, mid + 1, end, idx, val);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;

  cin >> N >> Q;
  while (Q--) {
    int command, p, q, x;

    cin >> command >> p;
    if (command == 1) {
      cin >> x;
      update(1, 1, N, p, x);
    } else {
      cin >> q;
      cout << sum(1, 1, N, p, q) << '\n';
    }
  }
}