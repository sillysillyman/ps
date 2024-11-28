#include <iostream>

using namespace std;

int rows[3'000];
int matrix[3'000][3'000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, q;

  cin >> N >> M >> q;
  for (int i = 0; i < N; i++) rows[i] = i;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) cin >> matrix[i][j];
  while (q--) {
    int command, i, j;

    cin >> command >> i >> j;
    if (command)
      swap(rows[i], rows[j]);
    else
      cin >> matrix[rows[i]][j];
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) cout << matrix[rows[i]][j] << ' ';
    cout << '\n';
  }
}