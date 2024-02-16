#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int lower[100000];
int upper[100000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, H;

  int arr[5] = {1, 2, 3, 4, 5};
  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0)
      cin >> lower[i / 2];
    else
      cin >> upper[i / 2];
  }
  sort(lower, lower + N / 2);
  sort(upper, upper + N / 2);

  int min_obstacle = 200000;
  map<int, int> obstacles;

  for (int obstacle, h = 1; h <= H; h++) {
    obstacle = N - (lower_bound(lower, lower + N / 2, h) - lower) -
               (upper_bound(upper, upper + N / 2, H - h) - upper);
    obstacles[obstacle]++;
    min_obstacle = min(min_obstacle, obstacle);
  }
  cout << min_obstacle << ' ' << obstacles[min_obstacle];
}