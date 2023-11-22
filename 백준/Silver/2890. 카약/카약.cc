#include <algorithm>
#include <iostream>

using namespace std;

char map[50][50];
tuple<int, int, int> info[10];

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
  return get<1>(a) < get<1>(b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  bool has_team = false;
  int R, C;
  int team_num;

  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> map[i][j];
      if (isdigit(map[i][j]) && !has_team) {
        team_num = map[i][j] - '0';
        info[team_num] = {team_num, C - j - 1, 0};
        has_team = true;
      }
    }
    has_team = false;
  }
  sort(info + 1, info + 10, compare);
  for (int i = 1; i < 10; i++) {
    if (i == 1)
      get<2>(info[i]) = 1;
    else {
      if (get<1>(info[i]) == get<1>(info[i - 1]))
        get<2>(info[i]) = get<2>(info[i - 1]);
      else
        get<2>(info[i]) = get<2>(info[i - 1]) + 1;
    }
  }
  sort(info + 1, info + 10);
  for (int i = 1; i < 10; i++) cout << get<2>(info[i]) << '\n';
}