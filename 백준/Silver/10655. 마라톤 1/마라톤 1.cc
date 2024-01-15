#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

Point checkpoints[100000];

int main() {
  int N;
  int total_dist = 0;
  int max_diff = 0;
  int skipped;

  cin >> N;
  for (int i = 0; i < N; i++) cin >> checkpoints[i].x >> checkpoints[i].y;
  for (int i = 0; i < N - 1; i++) {
    total_dist += abs(checkpoints[i + 1].x - checkpoints[i].x) +
                  abs(checkpoints[i + 1].y - checkpoints[i].y);
    if (i == 0) continue;

    int diff = (abs(checkpoints[i].x - checkpoints[i - 1].x) +
                abs(checkpoints[i].y - checkpoints[i - 1].y)) +
               (abs(checkpoints[i + 1].x - checkpoints[i].x) +
                abs(checkpoints[i + 1].y - checkpoints[i].y)) -
               (abs(checkpoints[i + 1].x - checkpoints[i - 1].x) +
                abs(checkpoints[i + 1].y - checkpoints[i - 1].y));
    
    max_diff = max(max_diff, diff);
  }
  cout << total_dist - max_diff;
}
// 0 0
//     | 11
// 8 3
//     | 7
// 11 -1
//     | 2
// 10 0
