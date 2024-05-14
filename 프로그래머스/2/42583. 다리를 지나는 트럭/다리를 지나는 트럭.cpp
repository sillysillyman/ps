#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int weight_sum = 0;
  deque<int> deque;

  for (int i = 0; i < bridge_length; i++) deque.push_back(0);
  reverse(truck_weights.begin(), truck_weights.end());
  while (!truck_weights.empty()) {
    weight_sum -= deque.front();
    deque.pop_front();
    if (weight_sum + truck_weights.back() > weight)
      deque.push_back(0);
    else {
      deque.push_back(truck_weights.back());
      weight_sum += truck_weights.back();
      truck_weights.pop_back();
    }
    ++answer;
  }
  while (deque.back() == 0) deque.pop_back();
  answer += deque.size();
  return answer;
}