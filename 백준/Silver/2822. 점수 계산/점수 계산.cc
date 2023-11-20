#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare_score_greater(pair<int, int> a, pair<int, int> b) {
  return a.second > b.second;
}

bool compare_index_less(pair<int, int> a, pair<int, int> b) {
  return a.first < b.first;
}

int main() {
  int score;
  int total_score = 0;
  vector<pair<int, int>> scores;

  for (int i = 1; i <= 8; i++) {
    cin >> score;
    scores.push_back({i, score});
  }
  sort(scores.begin(), scores.end(), compare_score_greater);
  sort(scores.begin(), scores.begin() + 5, compare_index_less);
  for (int i = 0; i < 5; i++) total_score += scores[i].second;
  cout << total_score << '\n';
  for (int i = 0; i < 5; i++) cout << scores[i].first << ' ';
}