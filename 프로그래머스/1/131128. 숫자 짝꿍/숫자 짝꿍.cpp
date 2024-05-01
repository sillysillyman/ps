#include <algorithm>
#include <map>
#include <string>

using namespace std;

string solution(string X, string Y) {
  string answer = "";
  map<char, int> x_map;
  map<char, int> y_map;

  for (char digit : X) x_map[digit]++;
  for (char digit : Y) y_map[digit]++;
  for (auto [k, v] : x_map) {
    for (int i = 0; i < min(v, y_map[k]); i++) answer.push_back(k);
  }
  sort(answer.begin(), answer.end(), greater());
  if (all_of(answer.begin(), answer.end(),
             [](char digit) { return digit == '0'; }))
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
  if (answer.empty()) answer = "-1";
  return answer;
}