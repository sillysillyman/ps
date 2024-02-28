#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
int indgrees[32001];
vector<int> graph[32001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;

  cin >> N >> M;
  for (int A, B, i = 0; i < M; i++) {
    cin >> A >> B;
    indgrees[B]++;
    graph[A].push_back(B);
  }
  for (int i = 1; i <= N; i++) {
    if (!indgrees[i]) pq.push(i);
  }
  while (!pq.empty()) {
    int prerequisite = pq.top();

    pq.pop();
    cout << prerequisite << ' ';
    for (int dependency : graph[prerequisite]) {
      if (--indgrees[dependency] == 0) pq.push(dependency);
    }
  }
}