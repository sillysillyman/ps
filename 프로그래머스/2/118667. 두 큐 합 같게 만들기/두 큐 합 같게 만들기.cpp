#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
  int answer = 0;
  long long q1_sum = accumulate(queue1.begin(), queue1.end(), 0LL);
  long long q2_sum = accumulate(queue2.begin(), queue2.end(), 0LL);
  queue<int> q1({queue1.begin(), queue1.end()});
  queue<int> q2({queue2.begin(), queue2.end()});

  if ((q1_sum + q2_sum) & 1) return -1;

  int threshold = (int)(1.5 * (q1.size() + q2.size()));

  while (q1_sum != q2_sum) {
    if (answer > threshold) return -1;
    if (q1_sum < q2_sum) {
      q1.push(q2.front());
      q1_sum += q2.front();
      q2_sum -= q2.front();
      q2.pop();
    } else if (q1_sum > q2_sum) {
      q2.push(q1.front());
      q2_sum += q1.front();
      q1_sum -= q1.front();
      q1.pop();
    }
    ++answer;
  }
  return answer;
}