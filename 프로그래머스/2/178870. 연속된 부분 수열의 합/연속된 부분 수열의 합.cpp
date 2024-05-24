#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
  vector<int> answer = {0, 999'999};
  vector<int> accumulated(sequence.size() + 1);

  for (int i = 1; i < sequence.size() + 1; i++)
    accumulated[i] += accumulated[i - 1] + sequence[i - 1];

  int left = 0, right = 1;

  while (right < accumulated.size()) {
    if (int sum = accumulated[right] - accumulated[left]; sum == k) {
      if (right - left - 1 < answer[1] - answer[0]) answer = {left, right - 1};
      left++;
    } else if (sum < k)
      right++;
    else if (sum > k)
      left++;
    if (left == right) right++;
  }
  return answer;
}