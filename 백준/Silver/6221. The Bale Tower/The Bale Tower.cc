#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

pair<int, int> bales[20];

int main() {
  int N, cnt = 0;

  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d", &bales[i].first, &bales[i].second);
  sort(bales, bales + N, [](pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first < p2.first;
  });

  vector<int> lis;
  for (int i = 0; i < N; i++) {
    auto it = lower_bound(lis.begin(), lis.end(), bales[i].second);
    if (it == lis.end())
      lis.push_back(bales[i].second);
    else
      *it = bales[i].second;
  }

  printf("%zu", lis.size());
}