#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, L;

  cin >> N >> L;
  for (int num, i = 0; i < N; i++) {
    cin >> num;
    if (i < L)
      pq.push({num, i});
    else {
      pq.push({num, i});
      while (pq.top().second <= i - L) pq.pop();
    }
    cout << pq.top().first << ' ';
  }
}