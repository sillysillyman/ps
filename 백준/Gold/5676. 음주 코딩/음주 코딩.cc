#include <iostream>

using namespace std;

int arr[100'001];
int tree[400'001];

int init(int node, int start, int end) {
  if (start == end) return tree[node] = arr[start];

  int mid = (start + end) / 2;

  return tree[node] =
             init(2 * node, start, mid) * init(2 * node + 1, mid + 1, end);
}

int multiply(int node, int start, int end, int left, int right) {
  if (start > right || end < left) return 1;
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;

  return multiply(2 * node, start, mid, left, right) *
         multiply(2 * node + 1, mid + 1, end, left, right);
}

int update(int node, int start, int end, int idx, int val) {
  if (idx < start || idx > end) return tree[node];
  if (start == end) return tree[node] = val;

  int mid = (start + end) / 2;

  return tree[node] = update(2 * node, start, mid, idx, val) *
                      update(2 * node + 1, mid + 1, end, idx, val);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;

  while (cin >> N >> K) {
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
      if (arr[i]) arr[i] /= abs(arr[i]);
    }
    init(1, 1, N);
    while (K--) {
      char cmd;
      int i;

      cin >> cmd;
      if (cmd == 'C') {
        int V;

        cin >> i >> V;
        if (V) V /= abs(V);
        update(1, 1, N, i, V);
      } else if (cmd == 'P') {
        int j;

        cin >> i >> j;
        if (int val = multiply(1, 1, N, i, j); val > 0)
          cout << '+';
        else if (val < 0)
          cout << '-';
        else
          cout << '0';
      }
    }
    cout << '\n';
  }
}