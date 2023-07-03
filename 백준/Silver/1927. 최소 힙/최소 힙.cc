#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int x;

    cin >> N;
    while (N--) {
        cin >> x;
        if (x == 0) {
            if (heap.empty()) cout << 0 << '\n';
            else {
                cout << heap.top() << '\n';
                heap.pop();
            }
        } else heap.push(x);
    }
}