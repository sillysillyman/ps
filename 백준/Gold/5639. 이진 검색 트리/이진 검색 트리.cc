#include <cstdio>

int tree[10'000];

void postorder(int start, int end) {
  if (start >= end) return;

  int right = start + 1;

  while (right < end && tree[right] < tree[start]) right++;
  postorder(start + 1, right);
  postorder(right, end);
  printf("%d\n", tree[start]);
}

int main() {
  int num, size = 0;
  while (~scanf("%d", &num)) tree[size++] = num;
  postorder(0, size);
}