#include <queue>
#include <vector>

using namespace std;

const int INF = 250'000'000;
vector<int> dists;
vector<vector<pair<int, int>>> graph;

void init(int size) {
  dists.assign(size + 1, INF);
  graph.assign(size + 1, vector<pair<int, int>>());
}

void dijkstra(int src) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  dists[src] = 0;
  pq.push({0, src});
  while (!pq.empty()) {
    auto [curr_dist, curr] = pq.top();

    pq.pop();
    if (curr_dist > dists[curr]) continue;
    for (auto& [next, dist] : graph[curr]) {
      if (int next_dist = curr_dist + dist; dists[next] > next_dist) {
        dists[next] = next_dist;
        pq.push({next_dist, next});
      }
    }
  }
}

int solution(int N, vector<vector<int>> road, int K) {
  int answer = 0;

  init(N);
  for (auto& info : road) {
    int from = info[0];
    int to = info[1];
    int dist = info[2];

    graph[from].push_back({to, dist});
    graph[to].push_back({from, dist});
  }
  dijkstra(1);
  for (int i = 1; i <= N; i++)
    if (dists[i] <= K) ++answer;
  return answer;
}