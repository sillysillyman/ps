#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2,
                vector<string> goal) {
  reverse(cards1.begin(), cards1.end());
  reverse(cards2.begin(), cards2.end());
  reverse(goal.begin(), goal.end());
  while (!goal.empty()) {
    if (!cards1.empty() && goal.back() == cards1.back()) {
      goal.pop_back();
      cards1.pop_back();
    } else if (!cards2.empty() && goal.back() == cards2.back()) {
      goal.pop_back();
      cards2.pop_back();
    } else
      return "No";
  }
  return "Yes";
}