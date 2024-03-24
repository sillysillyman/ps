#include <algorithm>
#include <iostream>

using namespace std;

int scores[5];

int main() {
  for (int i = 0; i < 5; i++) {
    for (int score, j = 0; j < 4; j++) {
      cin >> score;
      scores[i] += score;
    }
  }
  cout << max_element(scores, scores + 5) - scores + 1 << ' '
       << *max_element(scores, scores + 5);
}