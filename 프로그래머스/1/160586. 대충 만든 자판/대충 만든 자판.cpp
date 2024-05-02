#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
  vector<int> answer;

  for (string& target : targets) {
    int cnt = 0;

    for (int i = 0; i < target.size(); i++) {
      bool success = false;
      int idx = 100;

      for (string& keys : keymap) {
        if (auto it = find(keys.begin(), keys.end(), target[i]);
            it != keys.end()) {
          idx = min(idx, (int)(it - keys.begin()));
          success = true;
        }
      }
      if (!success) {
        cnt = -1;
        break;
      }
      cnt += idx + 1;
    }
    answer.push_back(cnt);
  }
  return answer;
}