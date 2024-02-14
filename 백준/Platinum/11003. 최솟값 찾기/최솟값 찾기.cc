#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int arr[5000000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, L;

  cin >> N >> L;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < N; i++) {
    if (i < L) {
      pq.push({arr[i], i});
      cout << pq.top().first << ' ';
    } else {
      pq.push({arr[i], i});
      while (pq.top().second <= i - L) pq.pop();
      cout << pq.top().first << ' ';
    }
  }
}
// 12 3
// 1 1 2 3 6 2 3 7 3 5 2 6