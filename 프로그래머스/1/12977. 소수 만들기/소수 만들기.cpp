#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  vector<bool> sieve(3'001, false);

  fill(sieve.begin() + 2, sieve.end(), true);
  for (int i = 2; i < 3'001; i++) {
    if (!sieve[i]) continue;
    for (int j = 2; i * j < 3'001; j++) sieve[i * j] = false;
  }
  for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i + 1; j < nums.size() - 1; j++) {
      for (int k = j + 1; k < nums.size(); k++) {
        if (sieve[nums[i] + nums[j] + nums[k]]) answer++;
      }
    }
  }
  return answer;
}