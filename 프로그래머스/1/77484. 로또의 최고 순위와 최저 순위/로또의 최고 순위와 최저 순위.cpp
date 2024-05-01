#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
  int zeros = 0, cnt = 0;
  vector<int> answer;

  for (int lotto : lottos) {
    if (!lotto)
      zeros++;
    else if (find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end())
      cnt++;
  }
  answer.push_back(min(6, 7 - (zeros + cnt)));
  answer.push_back(min(6, 7 - cnt));
  return answer;
}