#include <iostream>

using namespace std;

const long long INF = 1'000'000'000;
bool has_negative_cycle = false;
int N, M;
long long dists[501];
int edges[6000][3];

void bellman_ford(int src) {
  dists[src] = 0;
  for (int i = 1; i <= N; i++) {
    for (int curr, next, cost, j = 0; j < M; j++) {
      curr = edges[j][0];
      next = edges[j][1];
      cost = edges[j][2];
      if (dists[curr] != INF && dists[next] > dists[curr] + cost) {
        dists[next] = dists[curr] + cost;
        if (i == N) has_negative_cycle = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  for (int A, B, C, i = 0; i < M; i++) {
    cin >> A >> B >> C;
    edges[i][0] = A;
    edges[i][1] = B;
    edges[i][2] = C;
  }
  fill(dists + 1, dists + N + 1, INF);
  bellman_ford(1);
  if (has_negative_cycle)
    cout << -1;
  else {
    for (int i = 2; i <= N; i++) {
      if (dists[i] == INF)
        cout << -1 << '\n';
      else
        cout << dists[i] << '\n';
    }
  }
}