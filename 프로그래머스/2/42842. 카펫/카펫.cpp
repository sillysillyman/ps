#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
  int area = brown + yellow;
  vector<int> answer;

  for (int height, width, i = 1; i * i <= area; i++) {
    if (area % i) continue;
    height = i;
    width = area / i;
    if (2 * (height + width) - 4 == brown) {
      answer.push_back(width);
      answer.push_back(height);
      break;
    }
  }
  return answer;
}