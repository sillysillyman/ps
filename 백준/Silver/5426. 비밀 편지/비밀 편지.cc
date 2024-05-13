#include <cmath>
#include <iostream>

using namespace std;

char table[100][100];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;

  cin >> T;
  while (T--) {
    int size;
    string messages;

    cin >> messages;
    size = (int)sqrt(messages.size());
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) table[i][j] = messages[size * i + j];
    }
    for (int j = size - 1; j >= 0; j--) {
      for (int i = 0; i < size; i++) cout << table[i][j];
    }
    cout << '\n';
  }
}