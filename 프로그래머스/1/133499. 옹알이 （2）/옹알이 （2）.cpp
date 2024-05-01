#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
  int answer = 0;
  vector<string> babblings = {"aya", "ma", "woo", "ye"};

  for (string sound : babbling) {
    bool can_pronounce = true;
    string prev_babbling = "";

    while (!sound.empty()) {
      for (int j = 0; j < 4; j++) {
        if (sound.substr(0, babblings[j].size()) == babblings[j] &&
            babblings[j] != prev_babbling) {
          sound.erase(sound.begin(), sound.begin() + babblings[j].size());
          prev_babbling = babblings[j];
          can_pronounce = true;
          break;
        }
        can_pronounce = false;
      }
      if (!can_pronounce) break;
    }
    if (sound.empty()) answer++;
  }
  return answer;
}