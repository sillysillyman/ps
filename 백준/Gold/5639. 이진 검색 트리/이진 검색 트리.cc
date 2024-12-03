#include <algorithm>
#include <iostream>

using namespace std;

int tree[10'000];

void postorder(int start, int end) {
  if (start >= end) return;

  int parent = tree[start];
  int right = upper_bound(tree + start + 1, tree + end, parent) - tree;

  postorder(start + 1, right);
  postorder(right, end);
  cout << parent << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int num, size = 0;
  while (cin >> num) tree[size++] = num;
  postorder(0, size);
}