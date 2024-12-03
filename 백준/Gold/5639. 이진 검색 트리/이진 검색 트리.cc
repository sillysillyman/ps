#include <iostream>

using namespace std;

int tree[10'000];

void postorder(int start, int end) {
  if (start >= end) return;

  int right = start + 1;

  while (right < end && tree[right] < tree[start]) right++;
  postorder(start + 1, right);
  postorder(right, end);
  cout << tree[start] << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int num, size = 0;
  while (cin >> num) tree[size++] = num;
  postorder(0, size);
}