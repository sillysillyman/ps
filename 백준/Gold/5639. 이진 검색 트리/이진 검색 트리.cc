#include <algorithm>
#include <cstdio>

int tree[10'000];

void postorder(int start, int end) {
  if (start >= end) return;

  int parent = tree[start];
  int right = std::upper_bound(tree + start + 1, tree + end, parent) - tree;

  postorder(start + 1, right);
  postorder(right, end);
  printf("%d\n", parent);
}

int main() {
  int num, size = 0;
  while (~scanf("%d", &num)) tree[size++] = num;
  postorder(0, size);
}