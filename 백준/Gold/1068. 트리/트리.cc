#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(50);

void recursive_delete_node(int idx) {
  if (tree[idx][0] == -1) {
    tree[idx].clear();
    tree[idx].shrink_to_fit();
    return;
  }
  for (int child : tree[idx]) recursive_delete_node(child);
  tree[idx].clear();
  tree[idx].shrink_to_fit();
}

int main() {
  int N;
  int deleted;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int parent;

    cin >> parent;
    if (parent == -1) continue;
    tree[parent].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    if (tree[i].empty()) tree[i].push_back(-1);
  }
  cin >> deleted;
  recursive_delete_node(deleted);

  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (tree[i].empty()) continue;
    if (tree[i][0] == -1 || (tree[i].size() == 1 && tree[tree[i][0]].empty()))
      cnt++;
  }
  cout << cnt;
}