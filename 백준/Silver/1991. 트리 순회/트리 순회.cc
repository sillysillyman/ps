#include <iostream>

using namespace std;

char tree[26][3];

void preorder_traversal(int parent) {
    if (parent < 0) return;
    cout << tree[parent][0];
    preorder_traversal(tree[parent][1] - 'A');
    preorder_traversal(tree[parent][2] - 'A');
}

void inorder_traversal(int parent) {
    if (parent < 0) return;
    inorder_traversal(tree[parent][1] - 'A');
    cout << tree[parent][0];
    inorder_traversal(tree[parent][2] - 'A');
}

void postorder_traversal(int parent) {
    if (parent < 0) return;
    postorder_traversal(tree[parent][1] - 'A');
    postorder_traversal(tree[parent][2] - 'A');
    cout << tree[parent][0];
}

int main() {
    int N;
    char parent, left, right;

    cin >> N;
    while (N--) {
        cin >> parent >> left >> right;
        tree[parent - 'A'][0] = parent;
        tree[parent - 'A'][1] = left;
        tree[parent - 'A'][2] = right;
    }
    preorder_traversal(0);
    cout << '\n';
    inorder_traversal(0);
    cout << '\n';
    postorder_traversal(0);
}