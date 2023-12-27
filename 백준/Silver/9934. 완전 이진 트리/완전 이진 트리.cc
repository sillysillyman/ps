#include <iostream>
#include <vector>

using namespace std;

int K;
vector<int> tree;
vector<int> levels[10];

void get_nums_of_level(int begin, int mid, int end, int level, int depth) {
  levels[level].push_back(tree[mid]);
  if (depth == K) return;
  get_nums_of_level(begin, (begin + mid - 1) / 2, mid - 1, level + 1,
                    depth + 1);
  get_nums_of_level(mid + 1, (mid + end + 1) / 2, end, level + 1, depth + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> K;
  for (int i = 0; i < (1 << K) - 1; i++) {
    int num;

    cin >> num;
    tree.push_back(num);
  }
  get_nums_of_level(0, tree.size() / 2, tree.size() - 1, 0, 0);
  for (int i = 0; i < K; i++) {
    for (int num : levels[i]) cout << num << ' ';
    cout << '\n';
  }
}