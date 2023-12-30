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
  int root, deleted;

  cin >> N;
  for (int i = 0; i < N; i++) {
    int parent;

    cin >> parent;
    if (parent == -1) {
      root = i;
      continue;
    }
    tree[parent].push_back(i);
  }
  for (int i = 0; i < N; i++) {
    if (tree[i].empty()) tree[i].push_back(-1);
  }
//   cout << '\n';
//   for (int i = 0; i < N; i++) {
//     cout << i << ": ";
//     for (auto j : tree[i]) cout << j << " ";
//     cout << '\n';
//   }
  cin >> deleted;
  if (deleted == root) {
    cout << 0;
    return 0;
  }
  recursive_delete_node(deleted);
//   cout << '\n';
//   for (int i = 0; i < N; i++) {
//     cout << i << ": ";
//     for (auto j : tree[i]) cout << j << " ";
//     cout << '\n';
//   }

//   bool is_root_leaf = true;

//   if (tree[root].size() > 1) is_root_leaf = false;
//   for (int i = 0; i < N; i++) {
//     if (i == root) continue;
//     if (tree[i].empty()) continue;
//     is_root_leaf = false;
//   }
//   if (is_root_leaf) {
//     cout << 1;
//     return 0;
//   }

  int cnt = 0;

  for (int i = 0; i < N; i++) {
    if (tree[i].empty()) continue;
    if (tree[i][0] == -1 || (tree[i].size() == 1 && tree[tree[i][0]].empty())) {
        cnt++;
        // cout << i << " is leaf\n";
        // cout << "tree[" << i << "]: " << tree[i][0] << '\n';
    }
  }
  cout << cnt;
}