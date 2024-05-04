#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
  vector<string> answer(players.size());
  map<string, int> positions;

  for (int i = 0; i < players.size(); i++) positions[players[i]] = i;
  for (string name : callings) {
    swap(players[positions[name]], players[positions[name] - 1]);
    positions[players[positions[name]--]]++;
  }
  for (auto position : positions) answer[position.second] = position.first;
  return answer;
}