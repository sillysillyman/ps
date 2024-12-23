#include <cstdio>
#include <map>

using namespace std;

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    int K, N;
    map<int, pair<int, int>> record;

    scanf("%d", &K);
    for (int k, i = 0; i < K; i++) {
      scanf("%d", &k);
      record[k] = {0, i};
    }
    scanf("%d", &N);
    while (N--) {
      int n, h, m;

      scanf("%d%d%d", &n, &h, &m);
      if (record.find(n) == record.end() || h < 0) continue;
      record[n].first = 60 * h + m;
    }

    int cnt = 0, winner = 0;
    pair<int, int> max_record = {1440, 1'000};
    for (auto [k, v] : record) {
      if (0 < v.first && v.first <= 360) ++cnt;
      if ((v.first == max_record.first && v.second < max_record.second) ||
          0 < v.first && v.first < max_record.first) {
        winner = k;
        max_record = v;
      }
    }

    printf("%d %d\n", winner, cnt);
  }
}