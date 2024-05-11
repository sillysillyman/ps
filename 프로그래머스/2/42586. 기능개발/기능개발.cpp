#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  vector<int> days;

  for (int i = 0; i < progresses.size(); i++)
    days.push_back((int)ceil((100.0 - progresses[i]) / speeds[i]));

  int max = days[0];

  answer.push_back(1);
  for (int i = 1; i < days.size(); i++) {
    if (max < days[i]) {
      answer.push_back(1);
      max = days[i];
    } else
      answer.back()++;
  }
  return answer;
}