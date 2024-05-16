#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
  int answer;

  sort(data.begin(), data.end(), [&col](auto& v, auto& w) {
    if (v[col - 1] == w[col - 1]) return v[0] > w[0];
    return v[col - 1] < w[col - 1];
  });
  for (int i = row_begin - 1; i < row_end; i++) {
    int sum = 0;

    for (int num : data[i]) sum += num % (i + 1);
    if (i == row_begin - 1)
      answer = sum;
    else
      answer ^= sum;
  }
  return answer;
}