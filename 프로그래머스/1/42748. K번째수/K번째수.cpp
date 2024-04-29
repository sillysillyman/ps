#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for (auto& command : commands) {
    vector<int> range;

    for (int i = command[0] - 1; i < command[1]; i++) range.push_back(array[i]);
    sort(range.begin(), range.end());
    answer.push_back(range[command[2] - 1]);
  }
  return answer;
}