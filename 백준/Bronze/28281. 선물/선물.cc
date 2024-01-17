#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, X;

  cin >> N >> X;

  int cost = 2000000000;
  vector<int> costs(N);

  for (int i = 0; i < N; i++) cin >> costs[i];
  for (int i = 0; i < N - 1; i++) cost = min(cost, X * (costs[i] + costs[i + 1]));
  cout << cost;
}