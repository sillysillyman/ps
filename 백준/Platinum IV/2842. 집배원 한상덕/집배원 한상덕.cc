#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int min_degree_of_fatigue = 1e6;
pair<int, int> src;
int dst_cnt = 0;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
char map[50][50];
int contours[50][50];
bool visited[50][50];
vector<int> altitudes;

bool is_inside(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

int bfs(int low, int high) {
//   cout << '\n';
  int visit_cnt = 0;
  int min_altitude = 1e6;
  int max_altitude = 0;
  queue<pair<int, int>> q;

  q.push(src);
  visited[src.first][src.second] = true;
  while (!q.empty()) {
    auto [x, y] = q.front();

    if (map[x][y] == 'K') visit_cnt++;
    // cout << "cur x: " << x << " cur y: " << y << '\n';
    min_altitude = min(min_altitude, contours[x][y]);
    max_altitude = max(max_altitude, contours[x][y]);
    if (visit_cnt == dst_cnt) {
    //   cout << "max_altitude: " << max_altitude << '\n';
    //   cout << "min_altitude: " << min_altitude << '\n';
      return max_altitude - min_altitude;
    }
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (is_inside(nx, ny) && !visited[nx][ny] && (altitudes[low] <= contours[nx][ny]) && (contours[nx][ny] <= altitudes[high])) {
        visited[nx][ny] = true;
        q.push({nx, ny});
      }
    }
  }
  return -1;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'P') src = {i, j};
      else if (map[i][j] == 'K') dst_cnt++;
    }
  }
//   cout << '\n';
//   cout << "dst_cnt: " << dst_cnt << '\n';
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> contours[i][j];
      altitudes.push_back(contours[i][j]);
    }
  }
  sort(altitudes.begin(), altitudes.end());
  altitudes.erase(unique(altitudes.begin(), altitudes.end()), altitudes.end());
//   cout << "altitudes: ";
//   for (int altitude : altitudes) cout << altitude << ' ';
//   cout << '\n';
  
  int low = 0, high = 0;
  
  while (low <= high && high < altitudes.size()) {
    fill(&visited[0][0], &visited[N - 1][N], false);

    int degree_of_fatigue = bfs(low, high);

    // cout << "low: " << low << ", high: " << high << ", degree of fatigue: " << degree_of_fatigue << '\n';
    if (degree_of_fatigue == -1) high++;
    else {
      if (low == high) high++;
      else low++;
      min_degree_of_fatigue = min(min_degree_of_fatigue, degree_of_fatigue);
    }
  }
  cout << min_degree_of_fatigue;
}