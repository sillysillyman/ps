#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

Point checkpoints[100000];

int manhattan_distance(int src, int dst) {
  return abs(checkpoints[src].x - checkpoints[dst].x) +
         abs(checkpoints[src].y - checkpoints[dst].y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  int total_dist = 0;
  int max_diff = 0;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> checkpoints[i].x >> checkpoints[i].y;
  for (int i = 0; i < N - 1; i++) {
    total_dist += manhattan_distance(i + 1, i);
    if (i == 0) continue;

    int diff = manhattan_distance(i, i - 1) + manhattan_distance(i + 1, i) -
               manhattan_distance(i + 1, i - 1);

    max_diff = max(max_diff, diff);
  }
  cout << total_dist - max_diff;
}