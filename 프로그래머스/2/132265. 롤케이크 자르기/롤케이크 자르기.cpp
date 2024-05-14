#include <map>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
  int answer = 0;
  map<int, int> left, right;

  for (int type : topping) right[type]++;
  for (int type : topping) {
    if (left.size() == right.size()) ++answer;
    ++left[type];
    if (--right[type] == 0) right.erase(type);
  }
  return answer;
}