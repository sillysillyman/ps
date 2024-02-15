#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<>> min_heap;

  cin >> N;
  while (N--) {
    int num;

    cin >> num;
    if (max_heap.size() <= min_heap.size())
      max_heap.push(num);
    else
      min_heap.push(num);
    if (!min_heap.empty() && !max_heap.empty() &&
        max_heap.top() > min_heap.top()) {
      int max_top = max_heap.top();
      int min_top = min_heap.top();

      max_heap.pop();
      min_heap.pop();
      max_heap.push(min_top);
      min_heap.push(max_top);
    }
    cout << max_heap.top() << '\n';
  }
}