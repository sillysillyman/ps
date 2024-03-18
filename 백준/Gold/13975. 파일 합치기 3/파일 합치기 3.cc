#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int K;
    ll total_cost = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;

    cin >> K;
    for (int file, i = 0; i < K; ++i) {
      cin >> file;
      pq.push(file);
    }
    while (pq.size() > 1) {
      ll cost = 0;

      cost += pq.top();
      pq.pop();
      cost += pq.top();
      pq.pop();
      pq.push(cost);
      total_cost += cost;
    }
    cout << total_cost << '\n';
  }
}