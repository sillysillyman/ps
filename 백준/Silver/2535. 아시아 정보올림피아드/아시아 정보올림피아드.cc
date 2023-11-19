#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.second.second > b.second.second;
}

int main() {
  int N;
  int nation, student, score;
  vector<pair<int, pair<int, int>>> board;
  map<int, int> medals_of_nations;

  cin >> N;
  while (N--) {
    cin >> nation >> student >> score;
    board.push_back({nation, {student, score}});
  }
  sort(board.begin(), board.end(), cmp);

  int medal_cnt = 0;

  for (auto i : board) {
    if (medal_cnt == 3) break;
    nation = i.first;
    student = i.second.first;
    if (medals_of_nations[nation] >= 2) continue;
    medals_of_nations[nation]++;
    cout << nation << ' ' << student << '\n';
    medal_cnt++;
  }
}