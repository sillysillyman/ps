#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int K, M, P;

    scanf("%d%d%d", &K, &M, &P);

    vector<int> indeg(M, 0);
    vector<pair<int, bool>> num(M, {0, false});
    vector<vector<int>> graph(M);

    while (P--) {
      int A, B;

      scanf("%d%d", &A, &B);
      --A;
      --B;
      ++indeg[B];
      graph[A].push_back(B);
    }

    int max_num = 0;
    queue<int> q;
    for (int i = 0; i < M; ++i) {
      if (!indeg[i]) {
        q.push(i);
        num[i].first = 1;
      }
    }
    while (!q.empty()) {
      int curr = q.front();

      max_num = max(max_num, num[curr].first);
      q.pop();
      for (int next : graph[curr]) {
        if (!--indeg[next]) q.push(next);
        if (!num[next].second && num[next].first == num[curr].first) {
          num[next].first += 1;
          num[next].second = true;
        } else
          num[next].first = max(num[next].first, num[curr].first);
      }
    }

    printf("%d %d\n", K, max_num);
  }
}