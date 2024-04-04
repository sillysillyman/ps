#include <iostream>
#include <vector>

using namespace std;

struct Pos {
  int x, y;
};

int graph[10][10];
vector<Pos> poses;

bool does_overlap(Pos& a, Pos& b) {
  return (a.x == b.x && abs(a.y - b.y) <= 2) ||
         (a.y == b.y && abs(a.x - b.x) <= 2) ||
         (abs(a.x - b.x) <= 1 && abs(a.y - b.y) <= 1);
}

int sum_costs(Pos& p) {
  return graph[p.x - 1][p.y] + graph[p.x][p.y - 1] + graph[p.x][p.y] +
         graph[p.x][p.y + 1] + graph[p.x + 1][p.y];
}

int main() {
  int N;

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> graph[i][j];
      if (i == 0 || i == N - 1 || j == 0 || j == N - 1) continue;
      poses.push_back({i, j});
    }
  }

  int size = poses.size();
  int min_cost = 3000;

  for (int i = 0; i < size - 2; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (does_overlap(poses[i], poses[j])) continue;
      for (int k = 0; k < size; k++) {
        if (does_overlap(poses[j], poses[k]) ||
            does_overlap(poses[k], poses[i]))
          continue;
        min_cost = min(min_cost, sum_costs(poses[i]) + sum_costs(poses[j]) +
                                     sum_costs(poses[k]));
      }
    }
  }
  cout << min_cost;
}