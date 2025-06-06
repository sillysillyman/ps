#include <iostream>

using namespace std;
using pii = pair<int, int>;

const int MAX_N = 100'000;
int N;
int arr[MAX_N + 1];
pii tree[4 * MAX_N + 1];

pii init(int node, int start, int end) {
  if (start == end) return tree[node] = {arr[start], start};

  int mid = (start + end) / 2;
  return tree[node] =
             min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

pii query(int node, int start, int end, int left, int right) {
  if (right < start || end < left) return {1e9, MAX_N};
  if (left <= start && end <= right) return tree[node];

  int mid = (start + end) / 2;
  return min(query(2 * node, start, mid, left, right),
             query(2 * node + 1, mid + 1, end, left, right));
}

int get_max_area(int start, int end) {
  if (start > end) return 0;
  if (start == end) return arr[start];

  auto [min_height, min_idx] = query(1, 1, N, start, end);
  int area = min_height * (end - start + 1);
  area = max(area, get_max_area(start, min_idx - 1));
  area = max(area, get_max_area(min_idx + 1, end));

  return area;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  init(1, 1, N);
  cout << get_max_area(1, N);
}