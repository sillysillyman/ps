#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
  int size = elements.size();
  vector<int> consecutive_sums;

  for (int i = 0; i < size; i++) elements.push_back(elements[i]);
  for (int i = 1; i <= size; i++) {
    for (int j = 0; j < size; j++) {
      int sum = 0;

      for (int k = 0; k < i; k++) sum += elements[j + k];
      consecutive_sums.push_back(sum);
    }
  }
  sort(consecutive_sums.begin(), consecutive_sums.end());
  consecutive_sums.erase(
      unique(consecutive_sums.begin(), consecutive_sums.end()),
      consecutive_sums.end());
  return consecutive_sums.size();
}