#include <iostream>

using namespace std;

int main() {
  int score, apple = 0, banana = 0;

  cin >> score;
  apple += 3 * score;
  cin >> score;
  apple += 2 * score;
  cin >> score;
  apple += score;
  cin >> score;
  banana += 3 * score;
  cin >> score;
  banana += 2 * score;
  cin >> score;
  banana += score;
  if (apple > banana)
    cout << 'A';
  else if (apple < banana)
    cout << 'B';
  else
    cout << 'T';
}