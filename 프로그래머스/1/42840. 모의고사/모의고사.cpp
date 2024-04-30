#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
  int max_score = 0;
  vector<int> answer;
  vector<int> patterns[3] = {{1, 2, 3, 4, 5},
                             {2, 1, 2, 3, 2, 4, 2, 5},
                             {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
  pair<vector<int>, int> students[3];

  for (int i = 0; i < 3; i++) {
    while (students[i].first.size() < answers.size())
      students[i].first.insert(students[i].first.begin(), patterns[i].begin(),
                               patterns[i].end());
    students[i].first.erase(
        students[i].first.end() - students[i].first.size() + answers.size(),
        students[i].first.end());
  }
  for (int i = 0; i < answers.size(); i++) {
    for (int j = 0; j < 3; j++) {
      if (answers[i] == students[j].first[i]) students[j].second++;
      max_score = max(max_score, students[j].second);
    }
  }
  for (int i = 0; i < 3; i++) {
    if (students[i].second == max_score) answer.push_back(i + 1);
  }
  return answer;
}