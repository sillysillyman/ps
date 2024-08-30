#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> seq;

void dfs(int idx, int depth) {
  if (depth == M) {
    for (int num : seq) printf("%d ", num);
    printf("\n");
    return;
  }
  for (int i = idx; i < N; i++) {
    seq.push_back(arr[i]);
    dfs(i, depth + 1);
    seq.pop_back();
  }
}

int main() {
  scanf("%d%d", &N, &M);
  arr.resize(N);
  for (int e, i = 0; i < N; i++) scanf("%d", &arr[i]);
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  N = arr.size();
  dfs(0, 0);
}