#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
  int answer = 0;

  sort(citations.begin(), citations.end());
  for (int i = 0;
       citations.end() - lower_bound(citations.begin(), citations.end(), i) >=
       i;
       i++) {
    answer = i;
  }
  return answer;
}