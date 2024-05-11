#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
  int answer = 0;
  map<string, int> cnts;

  for (int i = 0; i < 10; i++) cnts[discount[i]]++;
  for (int i = 0; i <= discount.size() - 10; i++) {
    bool can_buy_all = true;

    for (int j = 0; j < want.size(); j++) {
      if (cnts[want[j]] < number[j]) {
        can_buy_all = false;
        break;
      }
    }
    if (can_buy_all) answer++;
    if (i == discount.size() - 10) break;
    --cnts[discount[i]];
    ++cnts[discount[i + 10]];
  }
  return answer;
}