#include <iostream>

using namespace std;
using ll = long long;

const int MAX = 1e9;
ll arr[100001];
ll tree[400001];

ll init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

ll find_min(int node, int start, int end, int left, int right) {
  if (left > end || right < start) return MAX;
  if (left <= start && right >= end) return tree[node];

  int mid = (start + end) / 2;

  return min(find_min(2 * node, start, mid, left, right),
             find_min(2 * node + 1, mid + 1, end, left, right));
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
    cout << find_min(1, 1, N, a, b) << '\n';
  }
}