#include <iostream>

using namespace std;

const int MAX_N = 100'000;
pair<int, int> arr[MAX_N + 1];
pair<int, int> tree[4 * MAX_N + 1];

pair<int, int> init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

pair<int, int> update(int node, int start, int end, int idx, int val) {
  if (idx < start || idx > end) return tree[node];
  if (start == end) return tree[node] = {val, idx};

  int mid = (start + end) / 2;

  return tree[node] = min(update(2 * node, start, mid, idx, val),
                          update(2 * node + 1, mid + 1, end, idx, val));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  init(1, 1, N);

  int M;

  cin >> M;
  while (M--) {
    int cmd;

    cin >> cmd;
    if (cmd == 1) {
      int i, v;

      cin >> i >> v;
      arr[i].first = v;
      update(1, 1, N, i, v);
    } else if (cmd == 2)
      cout << tree[1].second << '\n';
  }
}