#include <iostream>

using namespace std;

bool graph[100][100];

int main() {
  int x1, y1, x2, y2, area = 0;

  for (int i = 0; i < 4; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int x = x1; x < x2; x++) {
      for (int y = y1; y < y2; y++) graph[x][y] = true;
    }
  }
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (graph[i][j]) area++;
    }
  }
  cout << area;
}