#include <iostream>

using namespace std;

char article[250][250];

int main() {
  int R, C, ZR, ZC;

  cin >> R >> C >> ZR >> ZC;
  for (int i = 0; i < R * ZR; i += ZR) {
    for (int j = 0; j < C * ZC; j += ZC) cin >> article[i][j];
  }
  for (int i = 0; i < R * ZR; i++) {
    for (int j = 0; j < C * ZC; j++) {
      if (i % ZR) article[i][j] = article[i - 1][j];
      if (j % ZC) article[i][j] = article[i][j - 1];
    }
  }
  for (int i = 0; i < R * ZR; i++) {
    for (int j = 0; j < C * ZC; j++) cout << article[i][j];
    cout << '\n';
  }
}