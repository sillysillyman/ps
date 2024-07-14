#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  vector<float> scores;

  cin >> N;
  while (N--) {
    float score;

    cin >> score;
    scores.push_back(score);
  }
  sort(scores.begin(), scores.end());
  cout << fixed;
  cout.precision(3);
  for (int i = 0; i < 7; i++) cout << scores[i] << '\n';
}