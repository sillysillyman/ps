#include <map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
  string answer = "";
  map<string, int> list;

  for (auto player : participant) list[player]++;
  for (auto player : completion) list[player]--;
  for (auto record : list) {
    if (record.second) answer = record.first;
  }
  return answer;
}