#include <iostream>

using namespace std;

char decode[4][4] = {{'A', 'C', 'A', 'G'},
                     {'C', 'G', 'T', 'A'},
                     {'A', 'T', 'C', 'G'},
                     {'G', 'A', 'G', 'T'}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  string sequence;

  cin >> N >> sequence;
  while (sequence.length() > 1) {
    int row, col;
    int len = sequence.length();
    char row_base = sequence[len - 2];
    char col_base = sequence[len - 1];

    if (row_base == 'A')
      row = 0;
    else if (row_base == 'G')
      row = 1;
    else if (row_base == 'C')
      row = 2;
    else if (row_base == 'T')
      row = 3;
    if (col_base == 'A')
      col = 0;
    else if (col_base == 'G')
      col = 1;
    else if (col_base == 'C')
      col = 2;
    else if (col_base == 'T')
      col = 3;

    string base;

    base += decode[row][col];
    sequence.replace(len - 2, 2, base);
  }
  cout << sequence;
}