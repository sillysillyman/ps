#include <vector>

using namespace std;

vector<vector<int>> matrix;

void init_matrix(int rows, int columns) {
  matrix.assign(rows, vector<int>(columns));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) matrix[i][j] = i * columns + (j + 1);
  }
}

int rotate_and_find_minimun(int x1, int y1, int x2, int y2) {
  int pivot = matrix[x1][y1];
  int min_val = pivot;

  for (int j = y1 + 1; j <= y2; j++) {
    swap(matrix[x1][j], pivot);
    min_val = min(min_val, pivot);
  }
  for (int i = x1 + 1; i <= x2; i++) {
    swap(matrix[i][y2], pivot);
    min_val = min(min_val, pivot);
  }
  for (int j = y2 - 1; j >= y1; j--) {
    swap(matrix[x2][j], pivot);
    min_val = min(min_val, pivot);
  }
  for (int i = x2 - 1; i >= x1; i--) {
    swap(matrix[i][y1], pivot);
    min_val = min(min_val, pivot);
  }
  return min_val;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
  vector<int> answer;

  init_matrix(rows, columns);
  for (auto& query : queries)
    answer.push_back(rotate_and_find_minimun(query[0] - 1, query[1] - 1,
                                             query[2] - 1, query[3] - 1));
  return answer;
}