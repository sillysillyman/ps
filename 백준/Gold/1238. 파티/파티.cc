#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 10'000'000;
int times[1001][2];
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> backward_graph[1001];

void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  times[src][0] = 0;
  pq.push({times[src][0], src});
  while (!pq.empty()) {
    auto [curr_time, curr] = pq.top();

    pq.pop();
    if (curr_time > times[curr][0]) continue;
    for (auto [next, next_time] : graph[curr]) {
      if (times[next][0] > times[curr][0] + next_time) {
        times[next][0] = times[curr][0] + next_time;
        pq.push({times[next][0], next});
      }
    }
  }
  times[src][1] = 0;
  pq.push({times[src][1], src});
  while (!pq.empty()) {
    auto [curr_time, curr] = pq.top();

    pq.pop();
    if (curr_time > times[curr][1]) continue;
    for (auto [next, next_time] : backward_graph[curr]) {
      if (times[next][1] > times[curr][1] + next_time) {
        times[next][1] = times[curr][1] + next_time;
        pq.push({times[next][1], next});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, X;

  cin >> N >> M >> X;
  fill(&times[1][0], &times[N][2], INF);
  for (int src, dest, t, i = 0; i < M; i++) {
    cin >> src >> dest >> t;
    graph[src].push_back({dest, t});
    backward_graph[dest].push_back({src, t});
  }
  dijkstra(X);

  int max_time = 0;

  for (int i = 1; i <= N; i++)
    max_time = max(max_time, times[i][0] + times[i][1]);
  cout << max_time;
}