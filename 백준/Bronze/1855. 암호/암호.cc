#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int K;
  string encryted;

  cin >> K >> encryted;

  int row = encryted.length() / K;
  int col = K;
  vector<vector<char>> password(row, vector<char>(col));

  int pos = 0;

  for (int i = 0; i < row; i++) {
    string segment = encryted.substr(pos, col);

    if (i % 2) reverse(segment.begin(), segment.end());
    for (int j = 0; j < col; j++) password[i][j] = segment[j];
    pos += col;
  }
  for (int j = 0; j < col; j++) {
    for (int i = 0; i < row; i++) cout << password[i][j];
  }
}