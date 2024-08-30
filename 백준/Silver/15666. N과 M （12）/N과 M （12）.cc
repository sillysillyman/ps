#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> seq;

void dfs(int curr, int depth) {
  if (depth == M) {
    for (int num : seq) printf("%d ", num);
    printf("\n");
    return;
  }
  seq[depth] = arr[curr];
  for (int i = curr; i < N; i++) {
    dfs(i, depth + 1);
    if (depth == M - 1) break;
  }
}

int main() {
  scanf("%d%d", &N, &M);
  arr.resize(N);
  seq.resize(M);
  for (int e, i = 0; i < N; i++) scanf("%d", &arr[i]);
  sort(arr.begin(), arr.end());
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  N = arr.size();
  for (int i = 0; i < N; i++) dfs(i, 0);
}