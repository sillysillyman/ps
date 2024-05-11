#include <algorithm>
#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
  int answer = -1;

  sort(dungeons.begin(), dungeons.end());
  do {
    int fatigue_level = k;
    int cnt = 0;

    for (auto& dungeon : dungeons) {
      int required_fatigue_level = dungeon[0];
      int consumption = dungeon[1];

      if (fatigue_level < required_fatigue_level) break;
      fatigue_level -= consumption;
      cnt++;
    }
    answer = max(answer, cnt);
  } while (next_permutation(dungeons.begin(), dungeons.end()));
  return answer;
}