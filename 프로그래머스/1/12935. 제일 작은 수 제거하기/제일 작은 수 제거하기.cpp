#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
  int min_num = *min_element(arr.begin(), arr.end());
  vector<int> answer;

  for (int& num : arr) {
    if (num == min_num) continue;
    answer.push_back(num);
  }
  if (answer.empty()) answer.push_back(-1);
  return answer;
}