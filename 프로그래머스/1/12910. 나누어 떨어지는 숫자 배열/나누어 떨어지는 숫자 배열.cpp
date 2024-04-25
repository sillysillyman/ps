#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
  vector<int> answer;

  for (int& num : arr) {
    if (!(num % divisor)) answer.push_back(num);
  }
  if (answer.empty()) answer.push_back(-1);
  sort(answer.begin(), answer.end());
  return answer;
}