#include <iostream>

using namespace std;

int main() {
  int N;
  int sum = 0;
  int score = 1;
  bool correct;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> correct;
    if (correct) {
      sum += score;
      score++;
    } else
      score = 1;
  }
  cout << sum;
}