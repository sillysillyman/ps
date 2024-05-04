#include <algorithm>
#include <iostream>

using namespace std;

int cnts[1'001];
int table[1'001][5];

int main() {
  int N;

  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 5; j++) cin >> table[i][j];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (j == i) continue;
      for (int k = 0; k < 5; k++) {
        if (table[i][k] == table[j][k]) {
          cnts[i]++;
          break;
        }
      }
    }
  }
  cout << max_element(cnts + 1, cnts + N + 1) - cnts;
}