#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,
                             vector<vector<int>> arr2) {
  int R = arr1.size();
  int C = arr2[0].size();
  vector<vector<int>> answer(R, vector<int>(C, 0));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k < arr2.size(); k++)
        answer[i][j] += arr1[i][k] * arr2[k][j];
    }
  }
  return answer;
}