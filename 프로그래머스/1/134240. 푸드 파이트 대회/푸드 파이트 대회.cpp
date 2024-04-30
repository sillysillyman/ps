#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<int> food) {
  string answer, tmp;

  for (int i = 0; i < food.size(); i++) {
    for (int j = 0; j < food[i] / 2; j++) answer += to_string(i);
  }
  tmp = answer;
  reverse(tmp.begin(), tmp.end());
  return answer + "0" + tmp;
}