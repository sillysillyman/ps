#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  priority_queue<int> max_heap;

  cin >> N;
  while (N--) {
    int x;

    cin >> x;
    if (x == 0) {
      if (max_heap.empty())
        cout << 0 << '\n';
      else {
        cout << max_heap.top() << '\n';
        max_heap.pop();
      }
    } else
      max_heap.push(x);
  }
}