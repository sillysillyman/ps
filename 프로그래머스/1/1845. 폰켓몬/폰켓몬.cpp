#include <map>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  int cnt = 0;
  map<int, int> ponkemons;

  for (auto num : nums) ponkemons[num]++;
  cnt = ponkemons.size();
  if (cnt >= nums.size() / 2) answer = nums.size() / 2;
  else answer = cnt;
  return answer;
}