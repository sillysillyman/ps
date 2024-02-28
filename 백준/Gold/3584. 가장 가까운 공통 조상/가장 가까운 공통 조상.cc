#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int parent = 0;
  int depth = 0;
  vector<int> children;
};

Node tree[10001];

void init_depth(int node, int depth) {
  tree[node].depth = depth;
  for (auto child : tree[node].children)
    init_depth(child, depth + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T;

  cin >> T;
  while (T--) {
    int N, node1, node2;
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
      tree[i].parent = 0;
      tree[i].depth = 0;
      tree[i].children.clear();
    }
    for (int A, B, i = 0; i < N - 1; i++) {
      cin >> A >> B;
      tree[A].children.push_back(B);
      tree[B].parent = A;
    }

    int root;

    for (int i = 1; i <= N; i++) {
      if (tree[i].parent == 0) root = i;
    }
    init_depth(root, 1);
    // for (int i = 1; i <= N; i++) {
    //   cout << i << "'s depth = " << tree[i].depth << '\n';
    // }
    cin >> node1 >> node2;
    while (tree[node1].depth > tree[node2].depth)
      node1 = tree[node1].parent;
    while (tree[node1].depth < tree[node2].depth)
      node2 = tree[node2].parent;
    // cout << "after adjusting depth\n";
    while (node1 != node2) {
      node1 = tree[node1].parent;
      node2 = tree[node2].parent;
    }
    cout << node1 << '\n';
  }
}