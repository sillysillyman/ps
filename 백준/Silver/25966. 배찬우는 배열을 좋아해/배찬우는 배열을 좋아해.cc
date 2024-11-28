#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrix;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, q;

  cin >> N >> M >> q;
  matrix.assign(N, vector<int>(M));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> matrix[i][j];
  while (q--) {
    int command, i, j;

    cin >> command >> i >> j;
    if (command)
      swap(matrix[i], matrix[j]);
    else
      cin >> matrix[i][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cout << matrix[i][j] << ' ';
    cout << '\n';
  }
}