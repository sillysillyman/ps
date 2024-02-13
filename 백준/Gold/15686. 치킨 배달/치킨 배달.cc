#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
  int x, y;
};

int N, M;
int min_dist = 1e9;
int city[50][50];
vector<Point> chickens;
vector<Point> houses;

int main() {
  int num;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> num;
      if (num == 1) houses.push_back({i, j});
      else if (num == 2) chickens.push_back({i, j});
    }
  }

  vector<bool> mask(chickens.size(), false);

  for (int i = 0; i < M; i++) mask[i] = true;
  do {
    int dist_sum = 0;

    for (auto house : houses) {
      int dist = 1e9;
      for (int i = 0; i < chickens.size(); i++) {
        if (mask[i])
          dist = min(dist, abs(house.x - chickens[i].x) + abs(house.y - chickens[i].y));
      }
      dist_sum += dist;
    }
    min_dist = min(min_dist, dist_sum);
  } while (prev_permutation(mask.begin(), mask.end()));
  cout << min_dist;
}