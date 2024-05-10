#include <map>
#include <queue>
#include <vector>

using namespace std;

int solution(int k, vector<int> tangerine) {
  int answer = 0;
  priority_queue<pair<int, int>> pq;
  map<int, int> cnts;

  for (int& size : tangerine) cnts[size]++;
  for (auto& [size, cnt] : cnts) pq.push({cnt, size});
  while (k > 0) {
    k -= pq.top().first;
    pq.pop();
    ++answer;
  }
  return answer;
}