#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
  string answer;
  map<char, int> scores;

  answer.resize(4);
  for (int i = 0; i < survey.size(); i++) {
    if (choices[i] == 4) continue;
    if (choices[i] < 4)
      scores[survey[i][0]] += 4 - choices[i];
    else if (choices[i] > 4)
      scores[survey[i][1]] += choices[i] - 4;
  }
  answer[0] = scores['R'] >= scores['T'] ? 'R' : 'T';
  answer[1] = scores['C'] >= scores['F'] ? 'C' : 'F';
  answer[2] = scores['J'] >= scores['M'] ? 'J' : 'M';
  answer[3] = scores['A'] >= scores['N'] ? 'A' : 'N';
  return answer;
}