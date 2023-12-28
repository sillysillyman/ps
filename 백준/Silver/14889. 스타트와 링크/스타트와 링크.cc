#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int graph[20][20];

int combination(int n, int r) {
  if (r > (n >> 1)) return combination(n, n - r);
  if (n == r || r == 0) return 1;
  else return combination(n - 1, r - 1) + combination(n - 1, r); 
}

int main() {
  int N;
  int cnt = 0;
  vector<bool> team;

  cin >> N;

  int max_cnt = combination(N, (N >> 1)) >> 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) cin >> graph[i][j];
  }
  for (int i = 0; i < N / 2; i++) team.push_back(false);
  for (int i = 0; i < N / 2; i++) team.push_back(true);

  int diff = ~(1 << 31);

  do {
    if (cnt == max_cnt) break;

    vector<int> start, link;
    
    for (int i = 0; i < N; i++) {
      if (team[i]) start.push_back(i);
      else link.push_back(i);
    }

    int start_ability = 0;
    int link_ability = 0;
    vector<bool> start_ability_pair, link_ability_pair;

    for (int i = 0; i < N / 2 - 2; i++) start_ability_pair.push_back(false);
    for (int i = 0; i < 2; i++) start_ability_pair.push_back(true);
    for (int i = 0; i < N / 2 - 2; i++) link_ability_pair.push_back(false);
    for (int i = 0; i < 2; i++) link_ability_pair.push_back(true);
    do {
      int x = -1, y = -1;

      for (int i = 0; i < N / 2; i++) {
        if (start_ability_pair[i] && x == -1) x = i;
        else if (start_ability_pair[i] && x != -1) y = i;
        if (x != -1 && y != -1) break;
      }
      start_ability += graph[start[x]][start[y]] + graph[start[y]][start[x]];
    } while (next_permutation(start_ability_pair.begin(), start_ability_pair.end()));
    do {
      int x = -1, y = -1;

      for (int i = 0; i < N / 2; i++) {
        if (link_ability_pair[i] && x == -1) x = i;
        else if (link_ability_pair[i] && x != -1) y = i;
        if (x != -1 && y != -1) break;
      }
      link_ability += graph[link[x]][link[y]] + graph[link[y]][link[x]];
    } while (next_permutation(link_ability_pair.begin(), link_ability_pair.end()));
    cnt++;
    diff = min(diff, abs(start_ability - link_ability));
  } while (next_permutation(team.begin(), team.end()));
  cout << diff;
}