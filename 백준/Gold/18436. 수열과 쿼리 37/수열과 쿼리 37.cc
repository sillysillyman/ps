#include <iostream>

using namespace std;

const int MAX_N = 100'000;
int arr[MAX_N + 1];
pair<int, int> tree[4 * MAX_N + 1];

pair<int, int> operator+(const pair<int, int>& x, const pair<int, int>& y) {
  return {x.first + y.first, x.second + y.second};
}

pair<int, int> init(int node, int start, int end) {
  if (start == end) return tree[node] = {(arr[start] + 1) % 2, arr[start] % 2};

  int mid = (start + end) / 2;

  return tree[node] =
             init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

pair<int, int> count_parity(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return {0, 0};
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;

  return count_parity(2 * node, start, mid, left, right) +
         count_parity(2 * node + 1, mid + 1, end, left, right);
}

pair<int, int> update(int node, int start, int end, int idx, int val) {
  if (idx < start || end < idx) return tree[node];
  if (start == end) return tree[node] = {(val + 1) % 2, val % 2};

  int mid = (start + end) / 2;

  return tree[node] = update(2 * node, start, mid, idx, val) +
                      update(2 * node + 1, mid + 1, end, idx, val);
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
      int i, x;

      cin >> i >> x;
      arr[i] = x;
      update(1, 1, N, i, x);
    } else {
      int l, r;
      pair<int, int> parity;

      cin >> l >> r;
      parity = count_parity(1, 1, N, l, r);
      if (query == 2)
        cout << parity.first << '\n';
      else if (query == 3)
        cout << parity.second << '\n';
    }
  }
}