#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 3e5;
int knapsack[MAX_SIZE];
pair<int, int> jewelry[MAX_SIZE];
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> jewelry[i].first >> jewelry[i].second;
  for (int i = 0; i < K; i++) cin >> knapsack[i];

  sort(jewelry, jewelry + N);
  sort(knapsack, knapsack + K);

  int idx = 0;
  long long max_val = 0;
  for (int i = 0; i < K; i++) {
    while (idx < N && knapsack[i] >= jewelry[idx].first) {
      pq.push(jewelry[idx].second);
      idx++;
    }

    if (!pq.empty()) {
      max_val += pq.top();
      pq.pop();
    }
  }

  cout << max_val;
}