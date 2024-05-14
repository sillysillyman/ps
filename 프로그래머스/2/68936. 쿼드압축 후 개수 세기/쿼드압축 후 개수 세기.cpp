#include <vector>

using namespace std;

void compress(vector<vector<int>>& arr, int r, int c, int width,
              vector<int>& answer) {
  if (width == 1) return;

  bool is_all_zero = true;
  bool is_all_one = true;

  for (int i = r; i < r + width; i++) {
    for (int j = c; j < c + width; j++) {
      if (arr[i][j])
        is_all_zero = false;
      else
        is_all_one = false;
    }
  }
  if (is_all_zero) {
    answer[0] -= width * width - 1;
    return;
  } else if (is_all_one) {
    answer[1] -= width * width - 1;
    return;
  }
  compress(arr, r, c, width / 2, answer);
  compress(arr, r, c + width / 2, width / 2, answer);
  compress(arr, r + width / 2, c, width / 2, answer);
  compress(arr, r + width / 2, c + width / 2, width / 2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
  int n = arr.size();
  vector<int> answer(2, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j])
        ++answer[1];
      else
        ++answer[0];
    }
  }
  compress(arr, 0, 0, n, answer);
  return answer;
}